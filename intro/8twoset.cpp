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
    ll sum = (1+n)*n/2;
    if(sum % 2 == 1){
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    vector<ll> v1;
    ll tgt = sum/2;
    int last = 0;
    while(tgt >= n){
        last = n;
        v1.pb(n);
        tgt -= n;
        n--;
    }
    if(tgt != 0)
        v1.pb(tgt);
    
    vector<ll> v2;
   
    for(int i = 1; i<last; i++){
        if(i != tgt){
            v2.pb(i);
        }
    }

    cout<< v1.size() << "\n";
    for(auto i:v1){
        cout << i << " ";
    }

    cout << "\n" << v2.size() << "\n";
    for(auto i:v2){
        cout << i << " ";
    }
    //find one set that adds up to sum/2
    //other numbers are the other set
    return 0;
}