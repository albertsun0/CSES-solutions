#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

char board[8][8];
bool ld[15], rd[15], col[8];
int ans = 0;
void dfs(int r){
    // cout << r << "\n";
    if(r >= 8){
        ans += 1;
    }
    for (int i = 0; i < 8; i++){
        if (board[r][i] == '.' && !ld[i-r + 7] && !rd[i+r] && !col[i]){
            ld[i-r + 7] = 1, rd[i+r] = 1, col[i] = 1;
            dfs(r + 1);
            ld[i-r + 7] = 0, rd[i+r] = 0, col[i] = 0;
        }
    }
}

int main () {
    fio;

    vector<string> grid;
    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}