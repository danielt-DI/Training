#include <iostream>
#include <string>
#include "my_std_vector.h"
#include "file_handler.h"

struct my_struct {
    std::string str;
    int x;

    friend std::ostream& operator<<(std::ostream& os, const my_struct& s) {
        os << s.str << " " << s.x;
        return os;
    }
};

int main() {
/*
    my_std_vector<int> intv(3);
    std::cout << "Capacity : " << intv.capacity() << std::endl;
    intv.push_back(5);
    intv.push_back(5);
    intv.push_back(5);
    intv.push_back(5);
    std::cout << "Capacity : " << intv.capacity() << std::endl;
    intv.print();

    std::cout << std::endl;

    my_std_vector intvv(intv);
    intvv.push_back(10);
    intvv.print();
    intv.print();

    std::cout << std::endl;

    my_std_vector<std::string> strv(2);
    strv.push_back("Hello");
    strv.push_back("World");
    strv.push_back("!!");
    strv.print();

    std::cout << std::endl;
*/

    char to_print[] = "Some test text";
    char buff[10];
    fs::path p("/home/daniel/CLionProjects/cpp_training/test_file.txt");
    file_handler fh(p);
    fh.seekp(0);
    fh.write(to_print, sizeof(to_print) - 1);
    fh.seekg(5);
    fh.read(buff, 4);
    buff[4] = '\0';

    std::cout << buff << std::endl;

    std::cout << "Finished" << std::endl;

    return 0;
}
