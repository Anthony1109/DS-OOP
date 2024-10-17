#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        if(N == 0 && M == 0) {
            cout << "0 0" << endl;
            break; 
        }
        vector<int> v(N);
        for(auto &it : v) cin >> it;
        sort(v.begin(), v.end(), [M](int a, int b){
            int mod_a = a % M;
            int mod_b = b % M;           
            if(mod_a == mod_b){
                if(a % 2 == b % 2){
                    if(a % 2) return a > b;
                    else return a < b;
                }
                else return (a % 2) > (b % 2);
            }
            else return mod_a < mod_b;
        });
        cout << N << " " << M << endl;
        for(auto &it : v) cout << it << endl;
    }
}