#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        char c1, c2;
        cin >> c1 >> c2 >> n;

        long long int arr[n * n];
        for(int i = 0; i < n * n; i++){
            cin >> arr[i];           
        }

        bool isSymmetric = true;
        for(int i = 0; i < n * n; i++){
            if(arr[i] != arr[n * n-i-1] || arr[i] < 0){
                isSymmetric = false;
                break;
            }
        }
        
        cout << "Test #" << t << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << endl;
    }

    return 0;
}
