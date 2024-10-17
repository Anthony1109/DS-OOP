#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int M, N, Q;
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;

        string grid[M];
        for(int i = 0; i < M; i++){
            cin >> grid[i];
        }

        for(int i = 0; i < Q; i++){
            int r, c, max_side = 1;
            cin >> r >> c;
            while(r - max_side >= 0 && r + max_side < M && c - max_side >= 0 && c + max_side < N){
                bool flag = true;
                for(int j = r - max_side; j <= r + max_side; j++){
                    for(int k = c - max_side; k <= c + max_side; k++){
                        if(grid[j][k] != grid[r][c]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
                if(flag){
                    max_side++;
                }else{
                    break;
                }
            }
            cout << max_side * 2 - 1 << endl;        
        }
        
    }
}