#include <iostream>
#include <vector>
#include <algorithm>
#include <set> // 用來檢查重複的 sums
using namespace std;

int main() {
    int n;
    int t = 1;
    while (cin >> n) {
        vector<int> v(n);
        bool isB2Sequence = true;
        
        // 讀取序列
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            // 檢查當前元素是否為非正數
            if (v[i] <= 0 || v[i] > 10000) {
                isB2Sequence = false;
            }
            // 檢查序列是否不是遞增的
            if (i > 0 && v[i] <= v[i - 1]) {
                isB2Sequence = false;
            }
        }

        if (isB2Sequence) {
            set<int> sums;
            // 計算所有可能的 v[i] + v[j]
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int sum = v[i] + v[j];
                    // 檢查 sum 是否已經存在於 sums 中
                    if (sums.find(sum) != sums.end()) {
                        isB2Sequence = false;
                        break;
                    }
                    sums.insert(sum);
                }
                if (!isB2Sequence) break;
            }
        }

        // 根據 isB2Sequence 輸出結果
        if (isB2Sequence) {
            cout << "Case #" << t++ << ": It is a B2-Sequence." << endl << endl;
        } else {
            cout << "Case #" << t++ << ": It is not a B2-Sequence." << endl << endl;
        }
    }
    return 0;
}
