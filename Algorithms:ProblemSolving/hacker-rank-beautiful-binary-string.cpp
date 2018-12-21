#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    int count = 0;
    size_t pos = 0;
    do {
        pos = b.find("010", pos);
        if ( pos < string::npos ) {
            count++;
            pos += 3;
        }
    } while ( pos < b.size() );
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
