#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    while(cin >> input && input != "0"){
        int odd = 0; int even = 0;
        bool eleven = true;
        for(int i = 0; i < input.length(); i++){
            if(i % 2) odd += input[i] - '0';
            else even += input[i] - '0';
        }
        if((odd - even) % 11) eleven = false;
        if(eleven) cout << input << " is a multiple of 11." << endl;
        else cout << input << " is not a multiple of 11." << endl;
    }
}