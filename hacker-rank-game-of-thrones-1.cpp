/* Game of Thrones 1 - Hackerrank */
#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s){
    // Complete this function
    int flag = 0;
    int arr[26] = {0};
    string ret_val;
    for(int i = 0; i < s.size();i++){
      arr[s[i]-97]++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++) if(arr[i] % 2 != 0) odd++;

    if(odd > 1) ret_val = "NO";
    else ret_val = "YES";

    return ret_val;
}

int main() {
    string s;
    cin >> s;
    string result = gameOfThrones(s);
    cout << result << endl;
    return 0;
}
