
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") {
            break;
        }
        int carry = 0;
        int count = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            if (sum >= 10) {
                carry = 1;
                count++;
            } else {
                carry = 0;
            }
        }
        if (count == 0) {
            cout << "No carry operation." << endl;
        } else if (count == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }
    }
    return 0;
}

