#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
////////// R D L U
int dir[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
char let[4] = {'D', 'L', 'U', 'R'};

string explore(vector<vector<char>> &m, int r, int c, string s){
    
    if(r>=0 && r<m.size() && c >= 0 && c< m[0].size()){
        //cout << s << '\n';
        if(m[r][c] == 'B') return s;
        if(m[r][c] == '.' || m[r][c] == 'A'){
            m[r][c] = '#';
            string ret = "";
            for(int i = 0; i< 4; i++){
                string a = s + let[i];
                string temp = explore(m, r + dir[i][0], c + dir[i][1], a);
                if(ret == ""){
                    ret = temp;
                }
                if(temp != "" && temp.length() < ret.length()){
                   ret = temp;
                }
            }
            m[r][c] = '.';
            return ret;
        }
        return "";
    }
    return "";
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
    for(int r = 0; r < h; r++){
        for(int c = 0; c < w; c++){
            if(maze[r][c] == 'A'){
                string ans =  explore(maze, r, c, "");
                if(ans == ""){
                    cout << "NO";
                }
                else{
                    cout << "YES" << "\n";
                    cout << ans.length() << "\n";
                    cout << ans;
                }
                return 0;
            }
        }
    }
    return 0;
}

