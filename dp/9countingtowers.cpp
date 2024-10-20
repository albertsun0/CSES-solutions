#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
template<class T>
void piter(T args){for(auto x: args){cout << x <<" ";} cout << "\n";}
int MOD = 1e9+7;

int main () {
    fio;
    int n; cin >> n;
    vector<int> nums(n, 0);
    int mx = 0;
    for(int i =0; i < n; i++){
        cin >> nums[i];
        mx = max(mx, nums[i]);
    }
    vector<ll> two(mx, 1);
    vector<ll> one(mx, 1);
    two[0] = 2; 
    one[0] = 1;
    for (int i = 1; i < mx; i++){
        for (int j = 0; j < i; j++){
            two[i] += two[j];
            two[i] += one[i-j] + two[j] * 2;
            one[i] += one[j];
        }
    }   
    piter(two);
    piter(one);
    cout << two[mx - 1] << "\n";

    return 0;
}