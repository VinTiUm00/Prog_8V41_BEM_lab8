#include "task.hpp"

HashTable::HashTable() = default;

void HashTable::Add(const std::string& name, const double& cost){
    size_t hash = HashString(name);
    table[hash] = {name, cost};
}

bool HashTable::Delete(const std::string& name){
    size_t hash = HashString(name);
    return table.erase(hash) > 0;
}

double HashTable::Find(const std::string& name){
    size_t hash = HashString(name);
    auto it = table.find(hash);
    if (it != table.end()){
        return it->second.cost;
    }

    return 404;
}

bool HashTable::Empty(){
    return table.empty();
}

size_t HashTable::size(){
    return table.size();
}