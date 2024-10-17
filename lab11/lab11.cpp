#include <bits/stdc++.h>

using namespace std;

int main(){
    string line;
    set<string> validToppings = {"yasai", "ninniku", "abura", "karame"};
    set<string> validAdjustments = {"mashimashi", "mashi", "sukuname", "nuki"};
    unordered_map<string, string> ingredientMap;
    
    while(getline(cin, line)){
        stringstream ss(line);
        vector<string> words;
        string word;
        string ramen = "koramen";
        bool invalid = false;
        while(ss >> word){
            words.push_back(word);
        }
        if (words.empty()) {
            cout << "imi wakannai" << endl;
            continue;
        }

        if (words.back() == "koramen" || words.back() == "dairamen") {
            ramen = words.back();
            words.pop_back();
        }
        if (words.front() == "sonomama" && words.size() == 1) {
            cout << ramen << endl;
            continue;
        }
        else if (words.front() == "zen" && validAdjustments.find(words[1]) != validAdjustments.end()) {
            if(validAdjustments.find(words[1]) != validAdjustments.end() && words.size() == 2){
                cout << ramen << endl << "zen " << words[1] << endl;
                continue;
            }
            else{
                cout << "imi wakannai" << endl;
                continue;
            }
            
        }

        size_t i = 0;
        while(i < words.size()){
            if(validToppings.find(words[i]) == validToppings.end() && validAdjustments.find(words[i]) == validAdjustments.end()){
                cout << "imi wakannai" << endl;
                invalid = true;
                break;
            }
            else{
                if(ingredientMap.find(words[i]) != ingredientMap.end()){
                    cout << "imi wakannai" << endl;
                    invalid = true;
                    break;
                }
                string top = words[i];
                string adj = words[i+1];
                ingredientMap[top] = adj;
                i += 2;
            }
        }

        if(invalid) continue;
        cout << ramen << endl;
        for (const string &toppingName : {"yasai", "ninniku", "abura", "karame"}) {
            if (ingredientMap.find(toppingName) != ingredientMap.end()) {
                cout << toppingName << endl << ingredientMap[toppingName] << endl;
            }
        }

    }

}