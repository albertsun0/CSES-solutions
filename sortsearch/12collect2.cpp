#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int calc (vector<int> v){
    int round = 1;
    int pos = v[0];
    for (int i = 1; i < v.size(); i++){
        if(v[i] < pos){
            round++;
        }
        pos = v[i];
    }
    return round;
}

int main () {
    fio;
    int n; cin >> n;
    int m; cin >> m;
    vector<int> v;
    v.push_back(INT_MIN);
    for(int i = 0; i<n; i++){
        int a; cin>> a;
        v.push_back(a);
    }
    v.push_back(INT_MAX);
    int cur = calc(v);

    for(int i = 0; i<m; i++){
        int a,b; cin >> a >> b;
        // cout << a << " " << b << "\n";
        // int cur = init;
        int x = v[a];
        int y = v[b];

        
        if (v[a] < v[a-1]) cur -= 1;
        if (a == b - 1){
            if (v[b] < v[a]) cur -= 1;
        }
        else{
            if (v[a] > v[a+1]) cur -= 1;
            if (v[b] < v[b-1]) cur -= 1;
        }
        if (v[b] > v[b+1]) cur -= 1;

        swap(v[a], v[b]);

        cout << cur << "\n";
    } 
    // 5 4 3 2 1
    // 5 4 2 3 1

    // 1 2 3 4 5

    return 0;
}

/*
5 3
4 2 1 5 3
2 3
1 5
2 3
*/