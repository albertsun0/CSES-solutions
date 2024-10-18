#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define ll long long

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// ??????R??????U??????????????????????????LD????D?

bool vis[7][7];
int ans = 0;
string s;
int dirs[4][2] = {
    1,0,
    0,1,
    -1,0,
    0,-1
};

map<char, int> m = {{'D', 0}, {'R', 1}, {'U', 2}, {'L', 3}}; 

void dfs(int r, int c, int index){
    // cout << r << " " << c << " " << index << "\n";
    if (index == s.size()){
        if (r == 6 && c == 0){
            ans += 1;
        }
        return;
    }
    if (r == 6 && c == 0){
        return;
    }
    if (r == 6 && c > 0 && vis[r][c-1]){
        return;
    }
    if (c == 6 && r < 6 && vis[r+1][c]){
        return;
    }
    if (r == 0 && c < 6 && vis[r][c+1]){
        return;
    }
    if (r == 6 || r == 0){
        if (c > 0 && c < 6 && !vis[r][c-1] && !vis[r][c+1]){
            return;
        }
    }
    if (c == 6 || c == 0){
        if (r > 0 && r < 6 && !vis[r-1][c] && !vis[r+1][c]){
            return;
        }
    }
    if (c < 6 and c > 0){
        if (vis[r][c] && vis[r][c+1])
            if (r > 0 && r < 6 && !vis[r-1][c] && !vis[r+1][c]){
                return;
            }
    }
    if (r < 6 and r > 0){
        if (vis[r+1][c] && vis[r-1][c])
            if (c > 0 && c < 6 && !vis[r][c-1] && !vis[r][c+1]){
                return;
            }
    }

    vis[r][c] = 1;
    if (s[index] == '?'){
        for (int i = 0; i < 4; i++){
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < 7 && nc >=0 && nc < 7 && !vis[nr][nc]){
                dfs(nr,nc, index+1);
            }
        }
    }
    else{
        int nr = r + dirs[m[s[index]]][0];
        int nc = c + dirs[m[s[index]]][1];

        if (nr >= 0 && nr < 7 && nc >=0 && nc < 7 && !vis[nr][nc]){
            dfs(nr,nc, index+1);
        }
    }
    vis[r][c] = 0;
}

int main () {
    fio;
    cin >> s;
    dfs(0,0,0);
    cout << ans << "\n";

    return 0;
}