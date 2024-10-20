#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}
int MOD = 1e9+7;

int main () {
    fio;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp (n + 1, vector<int>(m+1, n+m));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++){
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min({
                            dp[i][j], 
                            dp[i-1][j] + 1,
                            dp[i][j-1] + 1,
                            dp[i-1][j-1] + 1
                            });
        }
    }

    // for (auto x: dp){
    //     piter(x);
    // }

    cout << dp[n][m] << "\n";
    return 0;
}

/*

 MOVIE
L12345
O11234
V112
E

*/