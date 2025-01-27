#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <vector>
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Please implement HashTable class in separate header and cpp file (HashTable.h and HashTable.cpp) //
// And you cannot modify any codes in main.cpp file.                                         //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "111611048_HashTable.h"

using namespace std;

/**
class to evaluate time cost
*/
template <typename Timer = std::chrono::milliseconds>
struct measure
{
    template <typename F, typename... Args>
    static typename Timer::rep execution(F func, Args &&... args)
    {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto duration = std::chrono::duration_cast<Timer>(std::chrono::high_resolution_clock::now() - start);
        return duration.count();
    }
};

/**
function to be evaluated
*/
void EvaluateFunc(HashTable hashTable, vector<string> testCases)
{
    string gender;
    int height, weight;
    for (int i = 0; i < testCases.size(); i++)
    {
        gender = hashTable[testCases.back()].getGender();
        height = hashTable[testCases.back()].getHeight();
        weight = hashTable[testCases.back()].getWeight();
        testCases.pop_back();
    }
}

int main()
{
    /** 
    HashTable is the class implemented by yourself, 5 member functions you need to implement as belows:
        1. addItem(key, gender, height, weight) : add data into your hash table
        2. operator[key]    : return item by selected key
        3. getGender()      : return gender by item
        4. getHeight()      : return height by item
        5. getWeight()      : return weight by item
    */
    HashTable hashTable;

    // for evaluation
    vector<string> testCases;

    // read data line by line
    std::ifstream infile("data.txt");
    string key, gender;
    int height, weight;

    vector<int> ans;
    while (infile >> key >> gender >> height >> weight)
    {
        hashTable.addItem(key, gender, height, weight);
        
        // collect evaluated test cases
        testCases.push_back(key);
        ans.push_back(height);
    }

    int count = 0;
    for(int i = 0; i < testCases.size(); i++)
    {
        if(hashTable[testCases[i]].getHeight() != ans[i]) count++;
    }
    cout << "Wrong answer: " << count << endl;

    // for(int i = 0; i < 10; i++)
    // {
    //     cout << "[\"" << testCases[i] << "\"]" << hashTable[testCases[i]].getGender() << " ";
    //     cout <<  hashTable[testCases[i]].getHeight() << " ";
    //     cout << hashTable[testCases[i]].getWeight() << endl;
    // }
    

    // Evauluate the speed of your hash table
    auto totalCost = measure<std::chrono::nanoseconds>::execution(EvaluateFunc, hashTable, testCases);
    cout << "Mean: " << totalCost / testCases.size() << " ns" << endl;

    return 0;
}