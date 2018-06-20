#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for(int i = 0; i < n; i++){
        string HashStairs = "";
        for(int j = 0; j < i+1; j++){
            HashStairs += "#";
        }
        cout << setw(n) << HashStairs << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
