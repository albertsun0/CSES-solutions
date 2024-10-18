#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nl "\n";
int bin(vector<int> v , int x){
    int left = 0;
    int right = v.size();
    while(left <= right){
        int mid = (right + left)/2;
        //cout << v[mid] << nl;
        if(x == v[mid]){
            return mid;
        }
        if(v[mid] < x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return left-1;
}

int main () {
    fio;
    // int n; cin >> n;
    // int m; cin >> m;
    // vector<int> v;
    // for(int i = 0; i<n ;i++){
    //     int a; cin >> a;
    //     v.pb(a);
    // }

    // sort(v.begin(), v.end());
    

    // for(int i = 0; i< m; i++){ 
    //     int x; cin >> x;
    //     if(v.size() == 0){
    //         cout << "-1" << nl;
    //     }
    //     if(x < v[0]){
    //         cout << "-1" << "\n";
    //     }
    //     else if(x > v[v.size() -1 ]){
    //         cout << v[v.size() -1] << "\n";
    //         v.pop_back();
    //     }
    //     else{
    //         int index = bin(v, x);
    //         cout << v[index] << "\n";
    //         v.erase(v.begin() + index);
    //     }
    //     // for(auto i : v){
    //     //     cout << i << " ";
    //     // }
    //     // cout << nl;
        
    // }

    int n; int m;
    multiset<int> s;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.begin()){
            cout << "-1" << nl;
        }
        else{
            cout << *(--it) << nl;
            s.erase(it);
        }
    }
    return 0;
}