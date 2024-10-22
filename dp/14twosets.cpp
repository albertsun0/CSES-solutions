#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
#include <unordered_map>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}
int MOD = 1e9+7;

int main () {
    fio;
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i ++ ){
        sum += i;
    }
    
    ll target = sum/2;

    if (sum % 2 == 1){
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    
    // lets always put n in the second set
    // we will never overcount. Any s1 will not
    // equal any s2, since n is always in the second set

    // equivalently, we can also comput only up to
    // target/4, (computing second set sum + n) = target
    // so we need to find sums of target/4

    for(int i = 1; i < n; i ++ ){
        for (int j = target; j >= 0; j--){
            if (dp[j] > 0 && j + i <= target){
                dp[j + i] += dp[j];
                dp[j + i] = dp[j + i] % MOD;
            }
        }
    }

    cout << dp[target] << "\n";
    return 0;
}