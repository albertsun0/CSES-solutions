#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


//prefix sums
int main () {
    fio;
    int n; cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i< n; i++){
        int s;
        int e;
        cin >> s >> e;
        v.push_back(make_pair(s,1));
        v.push_back(make_pair(e,-1));
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int count = 0;
    for(auto i : v){
        count += i.second;
        ans = max(ans,count);
    }
    cout << ans;
    return 0;
}