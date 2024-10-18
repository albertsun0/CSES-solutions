#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <map>
#include <limits.h>
int MOD = 1e9+7;

int main () {
    fio;
    
    int n; cin >> n;
    vector<vector<ll>> dp(n, vector<ll> (n,0));
    vector<string> grid (n, "");
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    dp[0][0] = 1;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (grid[i][j] == '*'){
                dp[i][j] = -1;
                continue;
            }
            if (i + j == 0) continue;
            if (i == 0 && j > 0 && dp[i][j-1] == -1){
                dp[i][j] = -1;
                continue;
            }
            if (j == 0 && i > 0 && dp[i-1][j] == -1){
                dp[i][j] = -1;
                continue;
            }
            if (i - 1 >= 0 and dp[i-1][j] > 0){
                dp[i][j] += dp[i-1][j] % MOD;
            }
            if (j - 1 >= 0 and dp[i][j-1] > 0){
                dp[i][j] += dp[i][j-1] % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    if (dp[n-1][n-1] < 0){
        cout << 0 << "\n";
        return 0;
    }
    cout << dp[n-1][n-1] % MOD << "\n";
    

    return 0;
}