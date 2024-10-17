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
    HashTable(size_t size = 23911) : tableSize(size), table(size) {}
    void addItem(const string& key, const string& gender, int height, int weight);
    const Item& operator[](const string& key) const;

private:
    vector<list<pair<string, Item>>> table;
    size_t hash(const string& key) const;
    size_t tableSize;
};

