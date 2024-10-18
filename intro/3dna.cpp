#include <iostream>
#include "vector"
using namespace std;
#define ll long long

int main () {
    string s;
    cin >> s;
    ll ans = 1;
    ll currentlen = 1;
    char current = s[0];
    for(int i = 1; i<s.length(); i++){
        if(s[i] == current){
            currentlen++;
        }
        else{
            current = s[i];
            currentlen = 1;
        }
        if(currentlen > ans){
            ans = currentlen;
        }
    }
    cout << ans;
    return 0;
}