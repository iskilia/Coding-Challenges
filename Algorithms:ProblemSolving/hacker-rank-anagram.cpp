#include <bits/stdc++.h>
#include <cmath> 
using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if(s.length() % 2 != 0){
        // Cannot split an odd-lengthed string into two equal length strings
        return -1;
    } else{
        vector<int> letterCount (26,0);
        for(int i = 0; i < s.length(); i++){
            if(i < s.length()/2){
                letterCount[s[i]-'a']++;
            } else {
                letterCount[s[i]-'a']--;
            }
        }
        int diffCount = 0;
        for(int i = 0; i < 26; i++){
            diffCount += abs(letterCount[i]);
        }
        return diffCount/2;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
