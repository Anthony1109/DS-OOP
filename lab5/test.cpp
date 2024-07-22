
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        int carry = 0;
        int count = 0;
        while(a > 0 || b > 0)
        {
            int digA = a % 10;
            int digB = b % 10;
            int sum = digA + digB + carry;
            if(sum >= 10)
            {
                carry = 1;
                count++;
            }
            else carry = 0;
            a /= 10;
            b /= 10;
        }
        if(count == 0) cout << "No carry operation." << endl;
        else if(count == 1) cout << count << " carry operation." << endl;
        else cout << count << " carry operations." << endl;
        
    }
    return 0;
}

