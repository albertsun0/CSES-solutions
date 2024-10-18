#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int first = 0;
        int second = 0;
        cin >> first >> second;
        if((first+second)%3 != 0){
            cout << "NO";
        }
        else if(first > second *2 || second > first*2){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << "\n";
    }
    return 0;
}