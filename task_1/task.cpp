#include "task.hpp"
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

extern std::vector<std::string> list;
extern std::unordered_set<size_t> list_hash;
extern size_t dupli;

size_t custom_hash(const std::string& surname){
    size_t magic_num = 7364;

    for (char c : surname){
        magic_num = (magic_num << 7) * 9 + (c - '0');
    }

    return magic_num;
}

void enrolled(const std::string& path){
    std::ifstream file(path);
    if (!file.is_open()){
        std::cerr << "The file could not be opened" << std::endl;
        return;
    }
    std::string surname;
    while (std::getline(file, surname)){
        size_t hash = custom_hash(surname);

        if (list_hash.find(hash) != list_hash.end()){
            dupli++;
        }
        else{
            list_hash.insert(hash);
            list.push_back(surname);
        }
    }
    file.close();
}

void unenrolled(const std::string& surname){
    size_t hash = custom_hash(surname);

    if (list_hash.find(hash) != list_hash.end()){
        dupli++;
    }
    else{
        list_hash.insert(hash);
        list.push_back(surname);
    }
}