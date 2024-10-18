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

    int current = 0;
    int multiple = 2;
    for(int i = 0; i<n; i++){
        current += multiple;
        if(current > n){
            if((n-i)%2 == 1){
                current += multiple;
            }
            //current += multiple;
            multiple *=2;
            current = current % n;
        }
        cout << current << " "; 
    }
    return 0;
}

//1 2 3 4 5 6 7 8
//2 4 6 8
//3 7 
//1 2 3 4 5 6 7 
//  x   x   x

// 2 4 6 1 5 7