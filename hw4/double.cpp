#include "double.h"
#include <bits/stdc++.h>
using namespace std;

HashTable::HashTable(size_t size) : tableSize(size), table(size), occupied(size, false) {}

size_t HashTable::hash1(const string& key) const {
    size_t hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + ch) % tableSize;
    }
    return hashValue;
}

size_t HashTable::hash2(const string& key) const {
    size_t hashValue = 1;
    for (char ch : key) {
        hashValue = (hashValue * 17 + ch) % tableSize;
    }
    return hashValue + 1; // Ensure non-zero step size
}

size_t HashTable::probe(size_t index, size_t i) const {
    return (index + i * hash2("")) % tableSize;
}

void HashTable::addItem(const string& key, const string& gender, int height, int weight) {
    size_t index = hash1(key);
    size_t startIndex = index;

    for (size_t i = 0; i < tableSize; ++i) {
        if (!occupied[index]) {
            // 空位，插入新元素
            table[index] = {key, Item(gender, height, weight)};
            occupied[index] = true;
            return;
        } else if (table[index].first == key) {
            // 已存在，更新元素
            table[index].second = Item(gender, height, weight);
            return;
        }
        index = probe(startIndex, i + 1);
    }
    throw overflow_error("Hash table is full");
}


const Item& HashTable::operator[](const string& key) const {
    size_t index = hash1(key);
    size_t startIndex = index;

    for (size_t i = 0; i < tableSize; ++i) {
        if (!occupied[index]) {
            // 空位，拋出異常
            throw out_of_range("Key not found");
        } else if (table[index].first == key) {
            // 找到對應元素
            return table[index].second;
        }
        index = probe(startIndex, i + 1);
    }

    throw out_of_range("Key not found");
}
