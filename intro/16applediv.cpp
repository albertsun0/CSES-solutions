#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <limits.h>
#include <cmath>
 
ll ans = LLONG_MAX;
 
void r(vector<ll> v, ll suml, ll sumr, int index){
    if(index >= v.size()){
        ans = min(ans, abs(sumr - suml));
        return;
    }
    r(v, suml + v[index], sumr, index+1);
    r(v, suml, sumr + v[index], index + 1);
}
 
int main () {
    fio;
    int n; cin >> n;
    vector<ll> v;
    for(int i = 0; i < n ; i++){
        ll a; cin >> a;
        v.pb(a);
    }
    r(v, 0, 0, 0);
 
    cout << ans;
 
    return 0;
}
