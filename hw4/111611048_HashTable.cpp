#include "111611048_HashTable.h"
#include <bits/stdc++.h>
using namespace std;

size_t HashTable::hash(const std::string& key) const {
    size_t hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + ch) % tableSize;
    }
    return hashValue;
}

void HashTable::addItem(const std::string& key, const std::string& gender, int height, int weight) {
    size_t index = hash(key);
    auto& bucket = table[index];

    for (auto& item : bucket) {
        if (item.first == key) {
            item.second = Item(gender, height, weight);
            return;
        }
    }

    bucket.emplace_back(key, Item(gender, height, weight));
}

const Item& HashTable::operator[](const string& key) const {
    size_t index = hash(key);
    const auto& bucket = table[index];
    
    for (const auto& item : bucket) {
        if (item.first == key) {
            return item.second;
        }
    }
    throw out_of_range("Key not found");
}


