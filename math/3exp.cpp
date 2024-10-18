#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int mod = 1e9+7;

ll r(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    if(b % 2 == 0){
        return (r(a, b/2) %mod *  r(a, b/2) % mod) % mod;
    }
    return (r(a, b/2)% mod *  r(a, b/2)% mod * a)% mod;
}

int main () {
    fio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        cout << r(a,r(b,c) % mod) << "\n";
    }
    
    return 0;
}