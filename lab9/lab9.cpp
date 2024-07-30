#include <iostream>
using namespace std;

int main(){
    long long int n;
    while(cin >> n && n != 0){
        int count = 0;
        while(n > 0){
            count += n % 10;
            n /= 10;
            if(count >= 10){
                count = count % 10 + count / 10;
            }
        }
        cout << count << endl;
    }
}