#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int mod = 1e9+7;

int sol(){
    int a; cin >>a;
    int ans = 0;
    for(int i = 1; i*i <= a; i++){
        if(a % i == 0){
            if(i * i != a){
                ans +=2;
            }
            else{
                ans += 1;
            }
        }
    } 
    return ans;
}
int main () {
    fio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
       cout << sol() << "\n"; 
    }
    
    return 0;
}