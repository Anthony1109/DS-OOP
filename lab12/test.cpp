
#include <bits/stdc++.h>
using namespace std;

void postorder(string preord, string inord){
    if(preord.size() == 0) return;
    char root = preord[0];
    int rootIndex = inord.find(root);
    postorder(preord.substr(1, rootIndex), inord.substr(0, rootIndex));
    postorder(preord.substr(rootIndex+1), inord.substr(rootIndex+1));
    cout << root;
}

int main(){
    string preord, inord;
    while(cin >> preord >> inord){
        postorder(preord, inord);
        cout << endl;
    }
}
