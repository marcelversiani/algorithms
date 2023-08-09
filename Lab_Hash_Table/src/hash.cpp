#include "hash.h"


Hash::Hash(int tablesize, int (*hf) (std::string) ) {
 // CONSTRUTOR
    _table.resize(tablesize);
    _hash_func = hf;
}

int Hash::add(std::string str, int &collisions) { 
    if(contains(str, collisions)) {
        return 0;
    }
    else {
        _table[hash(str)].push_front(str);
        return 1;
    }
    
}//add

int Hash::remove(std::string str, int &collisions) { 
    if(contains(str, collisions)) {
        _table[hash(str)].remove(str);
        return 1;
    }
    else {
        return 0;
    } 
    
}//remove

 
int Hash::hash(std::string str) { 
    
    return _hash_func(str);
    
}//hash
    
int Hash::contains(std::string str, int &collisions) { 
    collisions = 0;
    for(std::string s : _table[hash(str)]) {
        collisions++;
        if(s == str) {
            return 1;
        }
    }
    return 0;

}//contains


int Hash::worst_case() {
    int size;
    int max_size = 0;
    for(std::forward_list<std::string> ls : _table) {
        size = 0;
        for(std::string str : ls) {
            size += 1;
        }
        if(size > max_size) {
            max_size = size;
        }
    }
    return max_size;
    
}//worst_case

int Hash::size() {
    int total = 0;
    for(std::forward_list<std::string> ls : _table) {
        for(std::string str : ls) {
            total += 1;
        }
    }
    return total;
    
}//size

