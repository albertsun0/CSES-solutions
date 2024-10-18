#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007

int main () {
    fio;
    ll n; cin >> n;
    if(n < 6){
        cout << (1 << n-1);
        return 0;
    }
    ll dp [n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;

    for(int i=6; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % MOD;
    }
    cout << dp[n];
    return 0;
}