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
    int n; cin >> n;
    vector<int> v(n,0);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    int l = 0;
    map<int, int> m;
    int mx = 0;

    for(int i = 0; i<n; i++){
        if(m.find(v[i]) != m.end() && m[v[i]] >= l){
            l = m[v[i]]+1;
            m[v[i]] = i;
        } 
        else{
            m.insert({v[i],i});
        }
        //m.insert({v[i],i});
        mx = max(mx,i+1-l);

        cout << "info" << i << " "<< v[i] << " "  << l << "\n";
        cout << "map" << "\n";
         for(auto i: m){
            cout << i.first << " " << i.second << "\n";
        }
    }
    cout << mx;

    return 0;
}