#include "task.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::vector<std::string> list{};
std::unordered_set<size_t> list_hash{};
size_t dupli = 0;

int main(){
    setlocale(0, "");
    enrolled("students.txt");

    std::string str;
    std::cout << "Enter the last names of the people line by line\nTo exit the loop, enter \"end\":" << std::endl;

    std::getline(std::cin, str);
    while (str != "end"){
        unenrolled(str);
        std::getline(std::cin, str);
    }
    std::cout << "Number of votes: " << list_hash.size() << std::endl;
    std::cout << "Number of duplicates: " << dupli << std::endl;
    std::cout << "Last names of those who voted:" << std::endl;
    for (std::string a : list){
        std::cout << a << std::endl;
    }

    system("pause");
    return 0;
}