#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        char a, b;
        int N;
        cin >> a >> b >> N;
        long long int arr[N*N];
        bool isSym = true;
        for(int i = 0; i < N*N; i++) {
            cin >> arr[i];
            if(arr[i] < 0) isSym = false;
        }
        if(isSym)
        {
           for(int i = 0; i < N*N; i++){
                if(arr[i] != arr[N*N-i-1]){
                    isSym = false;
                    break;
                }
            } 
        }
        
        if(isSym) cout << "Test #" << t << ": " << "Symmetric." << endl;        
        else cout << "Test #" << t << ": " << "Non-symmetric." << endl;
    }
}