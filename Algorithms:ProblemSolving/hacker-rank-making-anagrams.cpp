#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(const string & s1, const string & s2) {
    unordered_map<char, int> letters;
    for(char c: s1){
        ++letters[c];
    }
    for(char c: s2){
        --letters[c];
    }
    int countDifference = 0;
    for(pair<char, int> pr: letters){
        countDifference += abs(pr.second);
    }
    return countDifference;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
