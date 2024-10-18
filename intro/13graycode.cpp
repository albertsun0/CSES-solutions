#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void recurse(string s, int len, bool flip){
    if(len == 0){
        cout << s << "\n";
        return;
    }
    string temp = s;
    string temp2 = s;
    if(flip){
        recurse(s + "1", len - 1, !flip);
        recurse(s + "0", len - 1, flip);
    }
    else{
        recurse(s + "0", len - 1, flip);
        recurse(s + "1", len - 1, !flip);
        
    }
    
}

int main () {
    fio;
    int n; cin >> n;

    recurse("", n, false);
    
    return 0;
}

/*
0000
0001
0011
0010
0110
0111
0101
0100

0000
0001
0011
0010

0000
0001

0011
0010

0110
0111
0101
0100

1100
1101
1111
1110
1010
1011
1001
1000


*/