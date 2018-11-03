#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    string sos = "SOS";
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != sos[i%3]) count++;
    }
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
