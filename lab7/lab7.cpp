#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        char c1, c2;
        cin >> c1 >> c2 >> N;
        bool isSymmetric = true;
        long long int arr[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                if (arr[i][j] < 0) isSymmetric = false;            
            }
        }
        
        if(isSymmetric){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(arr[i][j] != arr[N-i-1][N-j-1]){
                        isSymmetric = false;
                        break;
                    }
                }
                if(!isSymmetric){
                    break;
                }
            }
        }
        cout << "Test #" << t << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << endl;    
    }
}