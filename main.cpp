#include <iostream>
#include "my_vector.h"

int main() {

    my_vector<int> intv(3);
    std::cout << "Capacity : " << intv.capacity() << std::endl;
    intv.push_back(5);
    intv.push_back(5);
    intv.push_back(5);
    intv.push_back(5);
    std::cout << "Capacity : " << intv.capacity() << std::endl;
    intv.print();

    std::cout << std::endl;

    my_vector intvv(intv);
    intvv.push_back(10);
    intvv.print();
    intv.print();

    std::cout << std::endl;

    my_vector<std::string> strv(2);
    strv.push_back("Hello");
    strv.push_back("World");
    strv.push_back("!!");
    strv.print();

    std::cout << std::endl;

    std::cout << "Finished" << std::endl;

    return 0;
}
