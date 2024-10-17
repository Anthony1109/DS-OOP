#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <limits>

using namespace std;

vector<int> topologicalSort(int numLayers, const vector<int>& layers, const vector<pair<int, int>>& constraints) {
    map<int, vector<int>> adjList;
    map<int, int> inDegree;

    for (const auto& layer : layers) {
        inDegree[layer] = 0;
    }

    for (const auto& constraint : constraints) {
        int u = constraint.first;
        int v = constraint.second;
        adjList[v].push_back(u);
        inDegree[u]++;
    }

    queue<int> q;
    for (const auto& layer : layers) {
        if (inDegree[layer] == 0) {
            q.push(layer);
        }
    }

    vector<int> sortedOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sortedOrder.push_back(node);

        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return sortedOrder;
}

int main() {
    ifstream inputFile("sample data.txt");
    ofstream outputFile("TP_Sort_111611048.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int numLayers;
    while (inputFile >> numLayers) {
        vector<int> layers(numLayers);
        for (int i = 0; i < numLayers; ++i) {
            inputFile >> layers[i];
        }

        int numConstraints;
        inputFile >> numConstraints;

        vector<pair<int, int>> constraints;
        for (int i = 0; i < numConstraints; ++i) {
            int u, v;
            char c;
            inputFile >> u >> c >> v;
            constraints.emplace_back(u, v);
        }

        vector<int> sortedOrder = topologicalSort(numLayers, layers, constraints);

        for (int layer : sortedOrder) {
            if(layer != 0) outputFile << layer << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}