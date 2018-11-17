#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    bool count[26];
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            count[s[i] - 'a'] = true;
        }
    }
    for(int i = 0; i < 26; i++){
        if(!count[i]) return "not pangram";
    }

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
