#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void fill(vector<vector<char>> &m, int r, int c){
    if(r>=0 && r<m.size() && c >= 0 && c< m[0].size()){
        if(m[r][c] == '.'){
            m[r][c] = '#';
            fill(m, r+1, c);
            fill(m, r-1, c);
            fill(m, r, c+1);
            fill(m, r, c-1);
        }
    }
}

int main () {
    fio;
    int h; int w;
    cin >> h >> w;
    vector<vector<char>> maze;
    for(int i = 0; i< h; i++){
        vector<char> temp;
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            temp.pb(c);
        }
        maze.pb(temp);
    }
    // for(vector<char> v:maze){
    //     for(char c:v){
    //         cout << c;
    //     }
    //     cout << "\n";
    // }
    int ans = 0;
    for(int r = 0; r < h; r++){
        for(int c = 0; c < w; c++){
            if(maze[r][c] == '.'){
                ans++;
                fill(maze, r, c);
            }
        }
    }
    cout << ans;
    return 0;
}

