#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    string line;
    set<string> validToppings = {"yasai", "ninniku", "abura", "karame"};
    set<string> validAdjustments = {"mashimashi", "mashi", "sukuname", "nuki", "zen"};
    
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<string> words;
        string word;
        unordered_map<string, string> ingredientSettings;
        set<string> seenIngredients;
        string ramen = "koramen";
        string zenAdjustment;
        bool invalid = false;

        // 讀取所有詞
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.empty()) {
            cout << "imi wakannai" << endl;
            continue;
        }

        // 檢查麵量調整
        if (words.back() == "koramen" || words.back() == "dairamen") {
            ramen = words.back();
            words.pop_back();
        } else if (words[0] == "sonomama") {
            ramen = words.back();
            words.pop_back();
        } else if (words.size() > 1 && words[1] == "sonomama") {
            cout << "imi wakannai" << endl;
            continue;
        }

        size_t i = 0;
        while (i < words.size()) {
            if (words[i] == "zen") {
                if (!zenAdjustment.empty() || i + 1 >= words.size() || validAdjustments.find(words[i + 1]) == validAdjustments.end()) {
                    cout << "imi wakannai" << endl;
                    invalid = true;
                    break;
                }
                zenAdjustment = words[i + 1];
                i += 2;
            } else {
                
                string ingredient = words[i];
                string amount = words[i + 1];
                if (seenIngredients.find(ingredient) != seenIngredients.end()) {
                    cout << "imi wakannai" << endl;
                    invalid = true;
                    break;
                }
                ingredientSettings[ingredient] = amount;
                seenIngredients.insert(ingredient);
                i += 2;
            }
        }

        if (invalid) {
            continue;
        }

        if (!zenAdjustment.empty()) {
            for (auto& pair : ingredientSettings) {
                pair.second = zenAdjustment;
            }
        }

        cout << ramen << endl;
        for (const string& toppingName : {"yasai", "ninniku", "abura", "karame"}) {
            if (ingredientSettings.find(toppingName) != ingredientSettings.end()) {
                cout << toppingName << endl << ingredientSettings[toppingName] << endl;
            }
        }
    }

    return 0;
}
    