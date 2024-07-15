#include <iostream>
#include <string>
using namespace std;

bool isMultipleOfEleven(const string& numStr){
    int odd = 0, even = 0;
    for(size_t i = 0; i < numStr.length(); ++i){
        if(i % 2 == 0) odd += numStr[i] - '0'; 
        else even += numStr[i] - '0'; 
    }
    return (odd - even) % 11 == 0;
}

int main(){

    string N;
    while(cin >> N){
        if(N == "0") break;
        cout << N << " is " << (isMultipleOfEleven(N) ? "" : "not ") << "a multiple of 11." << endl;
    }

    return 0;
}