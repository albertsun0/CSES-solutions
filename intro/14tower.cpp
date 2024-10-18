#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void recursive(int n, int from, int to, int aux){
    if (n <= 0){
        return;
    }
    recursive(n-1, from, aux, to);
    cout << from << " " << to << "\n";
    recursive(n-1, aux, to, from);
}

//move n-1 to the middle 
//move n-2 to the middle

int main () {
    fio;
    int n; cin >> n;
    int total = (1 << n)-1;
    cout << total << "\n";
    recursive(n, 1, 3, 2);
}



//4
/*
Move n-1 disks from A to B using C
Move 1 disk from A to C
Move n-2 disks from B to A using C
Move 1 disk from A to C
now have n-2 disks on A ... 
*/

