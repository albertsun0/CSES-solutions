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
    
    // 9
    // 90 10 - 99
    // 900 100 - 999
    // 
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        int start = 0;
        int last = 9;
        int iter = 1;
        while(start + (iter * last * 10) < k){
            start = start + (iter * last * 10);
            iter += 1;
            last *= 10;
        }
        cout << start << "\n";

    }
    
    //cout << s;
    return 0;
}