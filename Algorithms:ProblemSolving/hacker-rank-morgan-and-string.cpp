#include <bits/stdc++.h>
#include <string>
using namespace std;

bool compare(string a, int i, string b, int j){
    while (i < a.length() && j < b.length()) {
        if (a[i] < b[j]) return true;
        else if (a[i] > b[j]) return false;
        i++;
        j++;
    }
    return i == a.length() ? false : true;
}
// Complete the morganAndString function below.
string morganAndString(string a, string b) {
    int i = 0, j = 0;
    string morganString = "";
    while(i < a.length() && j < b.length()){
        if(a[i] < b[j]){
            morganString.push_back(a[i++]);
        } else if(b[j] < a[i]){
            morganString.push_back(b[j++]);
        } else {
            if (compare(a, i + 1, b, j + 1)) {
                morganString.push_back(a[i++]);
                while (i < a.length() && a[i] == a[i - 1]) {
                    morganString.push_back(a[i++]);
                }
            } else {
                morganString.push_back(b[j++]);
                while (j < b.length() && b[j] == b[j - 1]) {
                    morganString.push_back(b[j++]);
                }
            }
        }
    }
    if(i < a.length()){
        morganString.append(a.substr(i));
    }
    if(j < b.length()){
        morganString.append(b.substr(j));
    }
    return morganString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
