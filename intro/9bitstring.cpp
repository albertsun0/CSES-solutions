#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
      //    1073741824
int main () {
    fio;
    ll n;
    cin >> n;
    //(A * B) mod C = (A mod C * B mod C) mod C
    // ll is 2^64
    // 2^ 62 = 73741817
    //(1 << n) % MOD;
    ll ans = 1;
    for(int i = 0; i<n; i++){
        ans *= 2;
        ans = ans % MOD;
    }
    cout << ans;
    return 0;
}