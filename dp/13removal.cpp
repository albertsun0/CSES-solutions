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

// unordered_map<int, int> memo;
// vector<int> nums;
// vector<int> prefix;

// int dp(int i, int j){
//     int key = i * 10000 + j;
//     if (memo.find(key) != memo.end()){
//         return memo[key];
//     }
//     if (i == j){
//         return nums[i];
//     }
//     // max other person can make if we take left/right
//     int total = prefix[j+1] - prefix[i];
//     int left = total - dp(i + 1, j);
//     int right = total - dp(i, j-1);
//     memo[key] = max(left, right);
//     return max(left, right);
// }
int main () {
    fio;
    int n;
    cin >> n;
    vector<int> nums;
    // int cur = 0;
    // prefix.push_back(0);
    ll sum = 0;
    for(int i = 0; i < n; i ++ ){
        int a; cin >> a; nums.push_back(a);
        sum += a;
        // cur += a;
        // prefix.push_back(cur);
    }
    vector<vector<ll>> dp (n, vector<ll>(n,0));
    // dp[l][r] = relative gain of current player for range l-r
    // min(dp[l+1][r], dp[l][r-1])
    for (int l = n - 1; l >= 0; l--){
        for (int r = l; r < n; r++ ){
            if (l == r){
                dp[l][r] = nums[l];
            }
            else{
                dp[l][r] = max(nums[l] - dp[l+1][r], 
                                nums[r] - dp[l][r-1]);
            }
        }
    }
    // score1 + score2 = sum
    // score1 - score2 = dp[0][n-1]
    // 2 * score1 = sum + dp[0][n-1]
    cout << (sum + dp[0][n-1])/2 << "\n";
    return 0;
}