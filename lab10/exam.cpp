#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int row, col, sq;
        cin >> row >> col >> sq;
        vector<string> grid(row);
        for(int i = 0; i < row; i++){
            cin >> grid[i];
        }
        vector<pair<int, int>> coor(sq);
        for(int i = 0; i < sq; i++){
            cin >> coor[i].first >> coor[i].second;
        }

        cout << row << " " << col << " " << sq << endl;
        for(int i = 0; i < sq; i++){
            int ans = 1;
            bool flag = false;
            int r = coor[i].first;
            int c = coor[i].second;
            while(1){
                if (r - ans < 0 || r + ans >= row || c - ans < 0 || c + ans >= col) break;
                char ch = grid[r][c];
                for(int j = r-ans; j <= r+ans; j++){
                    for(int k = c-ans; k <= c+ans; k++){
                        if(grid[r][c] != grid[j][k]){
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
                else ans++;
            }
            cout << ans*2-1 << endl;           
        }
    }
}