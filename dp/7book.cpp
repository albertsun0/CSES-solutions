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

int main () {
    fio;
    int n,m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m + 1));
    vector<vector<int>> books(n, vector<int>(2,0));

    for(int i = 0; i < n; i++){
        cin >> books[i][0];
    }
    for(int i = 0; i < n; i++){
        cin >> books[i][1];
    }

    // dp[0][0] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int price = books[i-1][0];
        int pages = books[i-1][1];
        if (price <= m){
            dp[i][price] = pages;
        }
        for(int j = 0; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(j - price >= 0 and dp[i-1][j-price] > 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-price] + pages);
            }
            ans = max(ans, dp[i][j]);
        }
        
    }

    // for (auto i: dp){
    //     piter(i);
    // }
    // cout << "\n";
    cout << ans << "\n";
    
    

    return 0;
}