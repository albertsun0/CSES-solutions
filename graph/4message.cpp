#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj;
    adj.resize(n);
    for(int i = 0; i<m; i++){
        int s;
        cin >> s;
        int e; 
        cin >> e;
        adj[s].pb(e);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        
    }
    return 0;
}