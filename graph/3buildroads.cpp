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
    vector<int> cities(n+1, -1);
    int m; cin >> m;
    for(int i = 0; i<m; i++){
        int a;
        int b;
        cin >> a >> b;
        if(cities[a] == -1 && cities[b] == -1){ //both nodes have not been seen yet
            cities[a] = 0;  //0 means that it is the head node for the component
            cities[b] = a; // any number means that node points to the head node of the component
        }
        else if(cities[a] == 0){
            cities[b] = a;
        }
        else if(cities[b] == 0){
            cities[a] == b;
        }
        else if(cities[a] > 0){
            cities[b] = cities[a];
        }
        else if(cities[b] > 0){
            cities[a] = cities[b];
        }
    }
    int count = 0;
    vector<int> add;
    for(int i = 1; i<=n; i++){
        if(cities[i] == 0 || cities[i] == -1){
            count++;
            add.pb(i);
        }
    }
    if(add.size() == 1){
        cout << 0;
        return 0;
    }
    cout << count - 1 << "\n";
    for(int i = 0; i< add.size()-1; i++){
        cout << add[i] << " " << add[i+1] << "\n";
    }

    return 0;
}