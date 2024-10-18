#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define ll long long

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; cin >> n;
    vector<int> v(n,0);
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        v[i] = a;
    }
    vector<int> towers;

    for (auto i: v){
        // upper_bound: element that comes after i
        auto it = upper_bound(towers.begin(), towers.end(), i);

        if(it == towers.end()){     
            towers.push_back(i);
        }
        else{
            towers[it - towers.begin()] = i;
        }
    }
    cout << towers.size() << "\n";
    return 0;
}

/*
5
3 8 2 1 5

8 5 3 2 1


*/