#include <bits/stdc++.h>

using namespace std;

int dpArray[5000][5000];

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            dpArray[i][j] = 0;
        }
    }
    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                // Check if a diagonal cell (a smaller subsequence) exists
                // If it does, increment by 1 + the value of the cell (size of the previous subsequence)
                // Otherwise set the cell equal to 1
                if(i > 0 && j > 0) {
                    dpArray[i][j] = dpArray[i-1][j-1] + 1;
                } else {
                    dpArray[i][j] = 1;
                }
            } else if(i == 0 && j > 0) {
                // Take the cell above
                dpArray[i][j] = dpArray[i][j-1];
            } else if(i > 0 && j == 0) {
                // Take the cell to the left
                dpArray[i][j] = dpArray[i-1][j];
            } else if(i > 0 && j > 0) {
                // Take the bigger of the cell above or to the left
                if(dpArray[i][j-1] > dpArray[i-1][j]) {
                    dpArray[i][j] = dpArray[i][j-1];
                } else {
                    dpArray[i][j] = dpArray[i-1][j];
                }
            }
        }
    }
    return dpArray[s1.length()-1][s2.length()-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
