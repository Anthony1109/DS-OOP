#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        string input;
        int index;
        getline(cin, input);
        for(int j = 0; j < input.size(); j++){
            if(input[j] == ' ') {
                cout << ' ';
                continue;
            }
            if(input[j] >= 'A' && input[j] <= 'Z'){
                input[j] += 32;
            }
            index = str.find(input[j]) - 2;
            cout << str[index];
        }
        cout << endl;       
    }
}