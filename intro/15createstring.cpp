#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void create(vector<char>& letters, string current, set<string>& ans){
    if(current.length() == letters.size()){
       ans.insert(current);
    }
    for(int i = 0; i < letters.size(); i++){
        if(letters[i] != '-'){
            char save = letters[i];
            letters[i] = '-';
            create(letters, current + save, ans);
            letters[i] = save;
        }
    }
}

int main () {
    fio;
    string s; cin >> s;
    vector<char> letters;
    for(char c:s){
        letters.pb(c);
    }
    set<string> ans;
    
    create(letters, "", ans);
    cout << ans.size() << "\n";
    for (auto s: ans){
        cout << s << "\n";
    }
    return 0;
}

