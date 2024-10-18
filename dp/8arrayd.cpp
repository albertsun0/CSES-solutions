#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <map>
#include <limits.h>
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}
int MOD = 1e9+7;

// given start, end, distance how many ways to traverse
int ways(int s, int e, int d, int mx, bool start=false, bool end=false){
    vector<vector<ll>> dp(d+1, vector<ll>(mx + 2,0));
    if (start){
        for (int i = 1; i <= mx; i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][s] = 1;
    }
    for (int i = 0; i < d; i++){
        for (int j = 1; j <= mx; j++){
            if (dp[i][j] > 0){
                dp[i+1][j-1] += dp[i][j] % MOD;
                dp[i+1][j] += dp[i][j] % MOD;
                dp[i+1][j+1] += dp[i][j] % MOD;
            }
        }
    }
    if(end){
        ll sum = 0;
        for (int i = 1; i <= mx; i++){
            sum += dp[d][i];
            sum %= MOD;
        }
        return sum % MOD;
    }
    return dp[d][e] % MOD;
}
int main () {
    fio;
    int n,m; cin >> n >> m;
    vector<int> nums (n,0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    ll ans = 1;
   
    int prev = -1;
    bool seq = false;
    int i = 0;
    if (nums[0] == 0){
        while(i < n && nums[i] == 0){
            i++;
        }
        if (i == n){
            cout << ways(0,0,n-1,m,true,true) << "\n";
            return 0;
        }
        ans *= ways(0,nums[i],i,m, true);
        ans %= MOD;
    }

    while (i < n){
        if (nums[i] == 0){
            seq = true;
        }
        else{
            // edge case
            if (i > 0 && nums[i-1] != 0 && abs(nums[i] - nums[i-1]) > 1){
                cout << 0 << "\n";
                return 0;
            }
            if (seq){
                ans *= ways(nums[prev], nums[i], i-prev, m);
                ans %= MOD;
            }
            seq = false;
            prev = i;
        }
        i++;
    }
    if (seq){
        ans *= ways(nums[prev], 0, n-prev - 1, m, false, true);
    }
    cout << ans % MOD << "\n";

    return 0;
}