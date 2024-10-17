#include <bits/stdc++.h>
using namespace std;

void add(string n){
    int sum = 0;
        for(int i = 0; i < n.size(); i++){
            sum += n[i] - '0';
        }
        string str = to_string(sum);
        if(str.size() > 1) add(str);
        else cout << str << endl;
}

int main(){
    string n;
    while(cin >> n && n != "0"){
        add(n);
    }
}