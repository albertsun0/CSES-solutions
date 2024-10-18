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
    int w; cin >> w;
    int ans = 0;
    vector<int> v;
    for(int i = 0; i< n; i++){
        int a; cin >> a;
        if(a >=w){
            ans++;
        }
        else{
            v.pb(a);
        }
    }

    sort(v.begin(), v.end());
    // for(auto i: v){
    //     cout << i << " ";
    // }
    // cout << "\n";
    int l = 0;
    int r = v.size()-1;

    while(r >= l){
        // cout << v[l] << " " << v[r] << "\n";
        if(v[l] + v[r] <= w){
            l++;
            r--;
            ans++;
        } 
        else if( v[l] + v[r] > w){
            r--;
            ans++;
        }
    }

    cout << ans;

    return 0;
}