#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    ll n; cin >> n;
    ll target; cin >> target;

    map<ll, int> m;
    for(int i = 0; i<n; i++){
        ll a;
        cin >> a;
        if(m.find(target-a) != m.end()){
            cout << m[target-a] << " ";
            cout << i+1;
            return 0;
        }
        m.insert({a, i+1});
    }
    cout << "IMPOSSIBLE";
    return 0;
}