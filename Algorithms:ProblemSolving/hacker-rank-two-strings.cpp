#include <bits/stdc++.h>
#include <string>
using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    int count = 0;
    string letters = "abcdefghijlkmnopqrstuvwxyz";
    bool hasCommonSubstring = false;
    for (int i = 0;i < letters.size();i++){
        if (s1.find(letters[i])!=string::npos && s2.find(letters[i])!=string::npos){
            hasCommonSubstring = true;
            break;
        }
    }
    return (hasCommonSubstring) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
