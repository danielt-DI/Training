#include <iostream>
#include "my_vector.h"

int main() {

    my_vector v(3);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    v.print();

    std::cout << std::endl;

    my_vector vv(v);
    vv.push_back(10);
    vv.print();
    v.print();

    std::cout << "Finished" << std::endl;

    return 0;
}
