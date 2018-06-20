#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long part1, part2;
    part1 = (n/s.size()) * count(s.begin(), s.end(), 'a');
    part2 = count(s.begin(),s.begin() + n%s.size(),'a');
    return part1+part2;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
