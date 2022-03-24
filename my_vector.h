//
// Created by daniel on 22/03/2022.
//

#include <iostream>
#include <memory>

#ifndef CPP_TRAINING_MY_VECTOR_H
#define CPP_TRAINING_MY_VECTOR_H

template <typename T>
class my_vector {
    std::unique_ptr<T[]> buff;
    int vec_capacity;
    int vec_size;

public:
    // constructor
    my_vector(int capacity): vec_capacity(capacity), vec_size(0), buff(std::make_unique<T[]>(capacity)) {}

    // copy constructor
    my_vector(const my_vector& vec);

    // copy assigment operator
    my_vector& operator=(const my_vector& vec);

    // move constructor
    my_vector(my_vector&& vec);

    // destructor
    //virtual ~my_vector(); - removed, buff is now a smart pointer.

    // vector interface
    int size() {return vec_size;}
    int capacity() {return vec_capacity;}
    void push_back(T elem);
    void print();
};

// copy constructor
template <typename T>
my_vector<T>::my_vector(const my_vector &vec): vec_capacity(vec.vec_capacity), vec_size(vec.vec_size), buff(std::make_unique<T[]>(vec.vec_capacity)) {
    for(int i = 0; i < vec_size; i++) {
        buff[i] = vec.buff[i];
    }
}

// assignment operator
template <typename T>
my_vector<T>& my_vector<T>::operator=(const my_vector &vec) {
    vec_size = vec.vec_size;
    vec_capacity = vec.vec_capacity;
    buff.reset();
    buff = std::make_unique<T[]>(vec.vec_capacity);

    for(int i = 0; i < vec_size; i++) {
        buff[i] = vec.buff[i];
    }
}

// move constructor
template <typename T>
my_vector<T>::my_vector(my_vector &&vec):vec_size(vec.vec_size), vec_capacity(vec.vec_capacity), buff(std::make_unique<T[]>(vec.vec_capacity)) {
    vec.buff = nullptr;
}

// vector interface
template <typename T>
void my_vector<T>::push_back(T elem) {
    if(vec_size == vec_capacity) {
        vec_capacity *= 2;
        std::unique_ptr<T[]> tmp = std::make_unique<T[]>(vec_capacity);

        for(int i = 0; i < vec_size; i++) {
            tmp[i] = buff[i];
        }

        buff.reset();

        buff = std::move(tmp);
    }

    buff[vec_size++] = elem;
}

template <typename T>
void my_vector<T>::print() {
    for(int i = 0; i < vec_size; i++) {
        std::cout << buff[i] << " ";
    }
    std::cout << std::endl;
}

#endif //CPP_TRAINING_MY_VECTOR_H