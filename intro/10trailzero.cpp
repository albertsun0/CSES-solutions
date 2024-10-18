#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;

    ll n;
    cin >> n;
    ll ans = 0;
    int multiple = 5;
    while(multiple <= n){
        //cout << ans << "\n";
        ans += n/multiple;
        multiple *=5;
    }
    cout << ans;
    return 0;
}