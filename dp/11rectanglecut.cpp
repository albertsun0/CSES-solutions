#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}
int MOD = 1e9+7;

int main () {
    fio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp (n + 1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == j){
                continue;
            }
            // its not always optimal to choose the 
            // biggest square
            dp[i][j] = INT_MAX;
            // horozontal cut
            for (int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 
                            dp[k][j] + dp[i-k][j] + 1);
            }
            for (int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 
                            dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    // for (auto x: dp){
    //     piter(x);
    // }

    cout << dp[n][m] << "\n";
    return 0;
}

/*
xxxxxxx
xxxxxxx
xxxxxxx
*/

// 3 x 6
// remove 2x2
// 2 x 4
// 1 x 6