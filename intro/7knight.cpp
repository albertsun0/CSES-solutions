#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll solve(ll n){

    //if(n == 0) return 0;
    if(n == 1) return 0;
    if(n == 2) return 6;
    if(n == 3) return 28;

    ll t = n*n;

    ll ans = 0;
    //first do outer edge
    //corner
    ans += (t - 3) * 4;
    //edge 1 from corner;
    ans += (t-4) * 8;
    //rest of edges have -5 choices
    //number of these edges on each side = n - 4;
    ans += (n-4) * (t-5) * 4;

    //inner edges
    //inner corner
    ans += 4 * (t-5);

    ans += (t-7) * (n-4) *4;
    ans += (t-9) * (n-4) * (n-4);

    return ans/2;
}

int main () {
    fio;
    ll n = 0;
    cin >> n;
    //cout << solve(6);
    for(ll i = 1; i<=n; i++){
        cout << solve(i) << "\n";
    }


    return 0;
}