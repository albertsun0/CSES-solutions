#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define ll unsigned long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//find value starting from mx^2,0
void findx(ll start, ll max, ll x, ll y){
    if(y < max){
        cout<<start-y+1;
    }
    else{
        cout << (start-y+1)-(max-x);
    }
}

//find value startinf from 0, mx^2
void findy(ll start, ll max, ll x, ll y){
    if(x < max){  
        cout<< start-x+1;
    }
    else{
        cout<< (start-x+1)-(max-y);
    }  
}

int main () {
    fio;
    ll n;
    ll y; 
    ll x;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> y >> x;
        ll m = max(x,y);
        
        ll t = m*m;
        //cout << m  << "\n";
        //cout << t  << "\n";
        if(t%2 == 0){
            findy(t,m,x,y);
        }
        else{
            findx(t,m,x,y);
        }
        cout << "\n";
    }

    return 0;
}
