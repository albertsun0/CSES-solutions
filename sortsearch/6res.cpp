#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; cin >> n;
    if(n == 1){return 1;}
    vector<vector<int>> v;
    for(int i = 0; i <n; i++){
        int a; int b;
        cin >> a >> b;
        vector<int> t;
        t.pb(a);
        t.pb(b);
        v.pb(t);
    }
    sort(v.begin(), v.end());

    int dp[n] = {};
    int end[n] = {};
    dp[0] = 1;
    end[0] = v[0][1];

    for(int i = 1; i < n; i++){
        if(v[i][0] >= end[i-1]){
            dp[i] = dp[i-1] + 1;
            end[i] = v[i][1];
        }
        else{
            dp[i] = dp[i-1];
            end[i] = min(end[i-1],v[i][1]);
        }
    }



    // for(auto i : dp){
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for(auto i: end){
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << dp[n-1];
    return 0;
}