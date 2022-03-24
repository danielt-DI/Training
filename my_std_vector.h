//
// Created by daniel on 24/03/2022.
//

#ifndef CPP_TRAINING_MY_STD_VECTOR_H
#define CPP_TRAINING_MY_STD_VECTOR_H

#include <iostream>
#include <vector>

template <typename T>
class my_std_vector {
    std::vector<T> buff;

public:
    // constructor
    my_std_vector(size_t capacity): buff(std::vector<T>()) {buff.reserve(capacity);}

    // copy constructor
    my_std_vector(const my_std_vector& vec): buff(std::vector<T>(vec.buff)) {}

    // copy assigment operator
    my_std_vector& operator=(const my_std_vector& vec) {buff = vec.buff;};

    // move constructor
    my_std_vector(my_std_vector&& vec): buff(std::vector<T>(vec.buff)) {}

    // vector interface
    int size() {return buff.size();}
    int capacity() {return buff.capacity();}
    void push_back(T elem) {buff.push_back(elem);}
    void print() {for(int i = 0; i < buff.size(); i++) std::cout << buff[i] << " "; std::cout << std::endl;}
};

#endif //CPP_TRAINING_MY_STD_VECTOR_H
