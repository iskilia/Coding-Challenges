#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    int sLength = s.length();
    bool isFunny = true;
    for(int i = 0; i < sLength/2; i++){
        int j = sLength - i - 1;
        if(abs(s[i] - s[i+1]) != abs(s[j-1]-s[j])){
            isFunny = false;
            break;
        }
    }
    string isFunnyString = (isFunny) ? "Funny" : "Not Funny";
    return isFunnyString;
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
