//
// Created by daniel on 22/03/2022.
//

#include <iostream>

#ifndef CPP_TRAINING_MY_VECTOR_H
#define CPP_TRAINING_MY_VECTOR_H

class my_vector {
    int* buff;
    int vec_capacity;
    int vec_size;

public:
    // constructor
    my_vector(int capacity): vec_capacity(capacity), vec_size(0), buff(new int[capacity]) {}

    // copy constructor
    my_vector(const my_vector& vec);

    // copy assigment operator
    my_vector& operator=(const my_vector& vec);

    // move constructor
    my_vector(my_vector&& vec);

    // destructor
    virtual ~my_vector();

    // vector interface
    int size() {return vec_size;}
    void push_back(int elem);
    void print();
};

// copy constructor
my_vector::my_vector(const my_vector &vec): vec_capacity(vec.vec_capacity), vec_size(vec.vec_size), buff(new int[vec.vec_capacity]) {
    for(int i = 0; i < vec_size; i++) {
        buff[i] = vec.buff[i];
    }
}

// assignment operator
my_vector& my_vector::operator=(const my_vector &vec) {
    vec_size = vec.vec_size;
    vec_capacity = vec.vec_capacity;
    delete[] buff;
    buff = new int[vec.vec_capacity];

    for(int i = 0; i < vec_size; i++) {
        buff[i] = vec.buff[i];
    }
}

// move constructor
my_vector::my_vector(my_vector &&vec):vec_size(vec.vec_size), vec_capacity(vec.vec_capacity), buff(new int[vec.vec_capacity]) {
    vec.buff = nullptr;
}

// destructor
my_vector::~my_vector() {
    delete[] buff;
}

// vector interface
void my_vector::push_back(int elem) {
    if(vec_size == vec_capacity) {
        vec_capacity *= 2;
        int* tmp = new int[vec_capacity];

        for(int i = 0; i < vec_size; i++) {
            tmp[i] = buff[i];
        }

        delete[] buff;

        buff = tmp;
    }

    buff[vec_size++] = elem;
}

void my_vector::print() {
    for(int i = 0; i < vec_size; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << std::endl;
}

#endif //CPP_TRAINING_MY_VECTOR_H