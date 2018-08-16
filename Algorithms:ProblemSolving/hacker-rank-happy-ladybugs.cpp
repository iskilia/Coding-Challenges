#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
  int underscore_count = 0;
  for(auto& c : b){
    if(c == '_') underscore_count++;
    if(underscore_count == b.size()) return "YES";
  }
  vector<int> color_counts(26, 0);
  for (auto& c : b) {
     if (c <= 'Z' && c >= 'A') {
         color_counts[c - 'A']++;
     }
  }
  bool yes = true;
  for (auto& c : color_counts) yes = yes && c != 1;
  for (size_t i = 1; underscore_count == 0 && i < b.size()-1 && yes; i+=2) yes = yes && (b[i] == b[i+1] || b[i] == b[i-1]);
  if(yes) return "YES";
  else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
