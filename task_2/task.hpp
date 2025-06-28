#ifndef TASK_HPP
#define TASK_HPP

#include <functional>
#include <string>
#include <unordered_map>

class HashTable{
    public:
        void Add(const std::string& name, const double& cost);
        bool Delete(const std::string& name);
        double Find(const std::string& name);
        bool Empty();
        size_t size();
        HashTable();
    private:
        struct Cell{
            std::string name;
            double cost;
        };
        std::unordered_map<size_t, Cell> table;
        std::hash<std::string> HashString;
};

#endif