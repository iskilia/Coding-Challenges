#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    string palin = s;
    // Iinitialize l and r by leftmost and
    // rightmost ends
    int l = 0;
    int r = n - 1;
    //  first try to make string palindrome
    while (l < r){
        // Replace left and right character by
        // maximum of both
        if (s[l] != s[r]){
            palin[l] = palin[r] = max(s[l], s[r]);
            k--;
        }
        l++;
        r--;
    }
    // If k is negative then we can't make
    // string palindrome
    if (k < 0) return "-1";
    l = 0;
    r = n - 1;
    while (l <= r){
        // At mid character, if K>0 then change
        // it to 9
        if (l == r){
            if (k > 0)
                palin[l] = '9'; 
        }
        // If character at lth (same as rth) is
        // less than 9
        if (palin[l] < '9')
        {
            /* If none of them is changed in the
                previous loop then subtract 2 from K
                and convert both to 9 */
            if (k >= 2 && palin[l] == s[l] &&
                palin[r] == s[r]){
                k -= 2;
                palin[l] = palin[r] = '9';
            }
            /*  If one of them is changed in the previous
                loop then subtract 1 from K (1 more is
                subtracted already) and make them 9  */
            else if (k >= 1 && (palin[l] != s[l] ||
                                palin[r] != s[r]))
            {
                k--;
                palin[l] = palin[r] = '9';
            }
        }
        l++;
        r--;
    }
    return palin;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
