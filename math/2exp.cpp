#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int mod = 1e9+7;

ll sol(){
    ll a; ll b; cin >> a >> b;
    //int mod = 1e9+7;

    int ans = 1;
    vector<int> powers;
    powers.pb(1);
    int pow = 1;
    while(pow < b){
        powers.pb(ans);
        ans *= powers[pow];
        pow++;

    }
    for(auto i: powers){
        cout << i << "\n";
    }
    return 0;
}

ll r(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    if(b % 2 == 0){
        return (r(a, b/2)%mod *  r(a, b/2) % mod) % mod;
    }
    return (r(a, b/2)% mod *  r(a, b/2)% mod * a)% mod;
    
}

int main () {
    fio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        cout << r(a,b) << "\n";
    }
    
    return 0;
}