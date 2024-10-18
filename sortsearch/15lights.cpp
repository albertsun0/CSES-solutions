#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define print()
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}

int main () {
    fio;
    int n; cin >> n;
    int m; cin >> m;

    set<int> lights;
    lights.insert(0);
    lights.insert(n);
    multiset<int> diffs;
    diffs.insert(n);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        auto l = next(lights.lower_bound(x), -1);
        auto r = lights.upper_bound(x);
        // cout << *l << " " << *r << "\n";
        int diff = *r - *l;
        // cout << diff << "\n";
        diffs.erase(diffs.lower_bound(diff));

        lights.insert(x);
        diffs.insert(x - *l);
        diffs.insert(*r - x);
        // test(diffs);
        cout << *next(diffs.end(),-1) << " ";
    }
    return 0;
}
