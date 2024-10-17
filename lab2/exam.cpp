#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<string> in(n);
    vector<pair<char, int>> ans(26, make_pair('A', 0));
    int max = 0;
    for(int i = 0; i < n; i++) getline(cin, in[i]);
    for(const auto& str : in){
        for(char c : str){
            
            if (isalpha(c)){
                c = toupper(c);
                ans[c - 'A'].first = c;
                ans[c - 'A'].second++;
            }            
        }
    }
    
    for (const auto& p : ans) {
        if (p.second > max) {
            max = p.second;
        }
    }

    for(int i = max; i >= 1; i--){
        for(int j = 0; j < ans.size(); j++){
            if(ans[j].second == i) cout << ans[j].first << " " << ans[j].second << endl;
        }
    }
}