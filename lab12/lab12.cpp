#include <bits/stdc++.h>
using namespace std;

void postorder(string preord, string inord){
    if (preord.size() == 0) return;
    char root = preord[0];
    int index = inord.find(root);
    postorder(preord.substr(1, index), inord.substr(0, index));
    postorder(preord.substr(index+1), inord.substr(index+1));
    cout << root;
}

int main(){
    string p, i;
    while(cin >> p >> i) {
        postorder(p, i);
        cout << endl;
    }
}