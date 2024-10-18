#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main () {
    fio;
    string s;
    cin >> s;
    vector<int> arr;
    arr.resize(26);
    for(int i = 0; i<s.length(); i++){
        arr[(int) s[i] - 65] ++;
    }

    int countOdd = 0;
    int indexOdd = 0;
    for (int i = 0 ; i<arr.size(); i++){
        if(arr[i] % 2 == 1) {
            indexOdd = i;
            countOdd++;
        }
    }

    if(countOdd > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i = 0; i< 26; i++){
        char c = (char) i + 65;
        for(int k = 0; k < arr[i]/2; k++){
            cout << c;
        }
    }
    if(countOdd == 1){
        char c = (char) indexOdd + 65;
        cout << c;
    }

    for(int i = 25; i >= 0; i--){
        char c = (char) i + 65;
        for(int k = 0; k < arr[i]/2; k++){
            cout << c;
        }
    }
        
    return 0;
}