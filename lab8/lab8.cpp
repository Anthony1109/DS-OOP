
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
    string s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string t;
        int index;
        getline(cin, t);
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        for(int i = 0; i < t.size(); i++){
            if(t[i] == ' '){
                cout << " ";
                continue;
            }
            index = s.find(t[i]) - 2;
            t[i] = s[index];
            cout << t[i];
        }
        cout << endl;
    }
}