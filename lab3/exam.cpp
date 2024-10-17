#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int t = 1;
    while(cin >> n){
        vector<int> v(n);
        bool isB2S = true;
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            if (v[i] <= 0 || v[i] > 10000) {
                isB2S = false;
            }
            if(i > 0 && v[i] <= v[i-1]){
                isB2S = false;
            }
        }
        if(isB2S){
            set<int> sums;
            for(int i = 0; i < n; i++){
                for(int j = i; j < n ; j++){
                    int sum = v[i] + v[j];
                    if(sums.find(sum) != sums.end()){
                        isB2S = false;
                        break;
                    }
                    sums.insert(sum);
                }
                if(!isB2S) break;
            }
        }
        if (isB2S) {
            cout << "Case #" << t++ << ": It is a B2-Sequence." << endl;
        } else {
            cout << "Case #" << t++ << ": It is not a B2-Sequence." << endl;
        }            
    }
}