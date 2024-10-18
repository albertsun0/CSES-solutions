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
    vector<int> v(n,0);
    for(int i = 0; i<n; i++){
        int a; cin>> a;
        v[a-1] = i;
    }
    int round = 1;
    int pos = v[0];
    for (int i = 1; i < n; i++){
        if(v[i] < pos){
            round++;
        }
        pos = v[i];
    }
    cout << round;


    return 0;
}