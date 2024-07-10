#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    int count[26] = {0};
    char letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 'A' + i;
    }
    for (int i = 0; i < n; i++){
        getline(cin, s);
        
        for (int j = 0; j < s.length(); j++){
            if (s[j] >= 'a' && s[j] <= 'z'){
                count[s[j] - 'a']++;
            }
            else if (s[j] >= 'A' && s[j] <= 'Z'){
                count[s[j] - 'A']++;
            }
        }
        
    }

    for (int j = 0; j < 26; j++){
            for (int k = j + 1; k < 26; k++){
                if (count[j] < count[k] || (count[j] == count[k] && letters[j] > letters[k])){
                    int temp = count[j];
                    count[j] = count[k];
                    count[k] = temp;
                    char tempChar = letters[j];
                    letters[j] = letters[k];
                    letters[k] = tempChar;
                }
            }
        }

        for (int j = 0; j < 26; j++){
            if (count[j] != 0){
                cout << letters[j] << " " << count[j] << endl;
            }
        }
}