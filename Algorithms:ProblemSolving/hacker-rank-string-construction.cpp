#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(const string & s) {
    unordered_map <char, int> letters;
    for(char c: s){
        ++letters[c];
    }
    return letters.size();
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
