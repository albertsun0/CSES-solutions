#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; int m; cin >> n; cin >> m;
    int dp [m+1];
    int vals [n];
    for(int i = 0; i< n; i++){
        cin >> vals[i];
    }

    for(int i = 0; i< m+1; i++){
            dp[i] = m+1;
    }
    dp[0] = 0;
    for(int coin = 1; coin < n+1; coin++){
        for(int val = 0; val < m+1; val++){
            int w = vals[coin-1];
            if(val >= w)
                dp[val] = min(dp[val-w]+1, dp[val]);
        }
    }
/*

4 27
2 5 10 1
 
*/
    // for(int j = 0; j< m+1; j++){
    //     cout << dp[j] << " ";
    // }
    // cout << "\n";

    
    if(dp[m] == m+1){dp[m] = -1;}
    cout << dp[m];

    return 0;
}


    // for(int coin = 1; coin < n+1; coin++){
    //     for(int val = 0; val < m+1; val++){
    //         int w = vals[coin-1];
    //         if(val < w){
    //             //cout << "less" << val;
    //             dp[coin][val] = dp[coin-1][val];
    //         }
    //         if(val + w <= m){
    //             if(dp[coin-1][val] == 0){
    //                 if(dp[coin-1][val+w] == 0 && val % w == 0)
    //                     dp[coin][val+w] = dp[coin][val] + 1;
    //                 else{
    //                     dp[coin][val+w] = dp[coin-1][val+w];
    //                 }
    //             }
    //             else{
    //                 dp[coin][val+w] = min(dp[coin][val]+1, dp[coin-1][val+w]);
    //             }
    //         }
            
    //     }
    // }