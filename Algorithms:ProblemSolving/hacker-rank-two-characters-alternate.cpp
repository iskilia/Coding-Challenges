#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    vector<int> frequency(26,0);
    for(const char &c : s)frequency[c-'a']++;
    int max = 0;
    bool valid;
    char last;
    for(int i = 0; i < frequency.size(); i++){
        if (frequency[i] == 0) continue;
        for (int j = i+1; j < frequency.size(); j++) {
            if (frequency[j] == 0) continue;
            last = -1;
            valid = true;
            for (const char& c : s) {
                if (c == char(i+'a') || c == char(j+'a')) {
                    if (last == c) {
                        valid = false;
                        break;
                    }
                    last = c;
                }
            }
            if (valid && std::abs(frequency[i] - frequency[j]) <= 1)
                max = std::max(max, frequency[i] + frequency[j]);
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
