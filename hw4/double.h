#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    Item() : gender("male"), height(0), weight(0) {}
    Item(const string& gender, int height, int weight)
        : gender(gender), height(height), weight(weight) {}

    string getGender() const { return gender; }
    int getHeight() const { return height; }
    int getWeight() const { return weight; }

private:
    string gender;
    int height;
    int weight;
};

class HashTable {
public:
    HashTable(size_t size = 23911); 
    void addItem(const string& key, const string& gender, int height, int weight);
    const Item& operator[](const string& key) const;

private:
    vector<pair<string, Item>> table;
    vector<bool> occupied; // 用來標記每個位置是否被佔用
    size_t tableSize;

    size_t hash1(const string& key) const;
    size_t hash2(const string& key) const;
    size_t probe(size_t index, size_t i) const;
};

