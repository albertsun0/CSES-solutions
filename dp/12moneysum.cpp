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
    int n;
    cin >> n;
    int mx = 100 * 1001;
    vector<int> nums(n,0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    vector<int> dp(mx + 1, 0);
    dp[0] = 1;
    for (auto c:nums){
        for (int i = mx - c; i >= 0; i--){
            if (dp[i] > 0){
                dp[i + c] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= mx; i++){
        if (dp[i] > 0){
            count++;
        }
    }
    cout << count << "\n";
    for (int i = 1; i <= mx; i++){
        if (dp[i] > 0){
            cout << i << " ";
        }
    }
    cout << "\n";
    
    // piter(dp);
    
    return 0;
}

// 0 1 2 3 4 5 6 7