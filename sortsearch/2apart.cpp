#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; int m; int k;
    cin >> n >> m >> k;

    vector<int> desired;
    vector<int> sizes;

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        desired.pb(a);
    }

    for(int i = 0; i< m; i++){
        int a; cin >> a;
        sizes.pb(a);
    }

    sort(desired.begin(), desired.end());
    sort(sizes.begin(), sizes.end());
    
    int pd = 0;
    int ps = 0;
    int ans = 0;
    while(pd < n && ps < m){
        //cout << desired[pd] << " " << sizes[ps] << "\n";
        if(abs(desired[pd] - sizes[ps]) <= k){
            //cout << "add" << "\n";
            ans++;
            pd++;
            ps++;
        }
        else{
            if(desired[pd] > sizes[ps]){
                ps++;
            } 
            else{
                pd++;
            }
        }
        
    }
    cout << ans;
    return 0;
}