#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), [m](int a, int b) {
            int mod_a = a % m;
            int mod_b = b % m;
            if (mod_a != mod_b) {
                return mod_a < mod_b;
            } else {
                bool a_is_odd = (a % 2 != 0);
                bool b_is_odd = (b % 2 != 0);
                if (a_is_odd != b_is_odd) {
                    return a_is_odd; // 奇數排在偶數前
                } else if (a_is_odd && b_is_odd) {
                    return a > b; // 兩個奇數，較大的排在前
                } else {
                    return a < b; // 兩個偶數，較小的排在前
                }
            }
        });
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << endl;
        }
        
    }
    cout << "0 0" << endl;
}


