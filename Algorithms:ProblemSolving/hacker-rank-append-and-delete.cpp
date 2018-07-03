#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
  int commonLength = 0, min_length = min(s.length(), t.length());
  for(int i = 0; i < min_length; i++){
    if(s[i] == t[i]){
      commonLength++;
    } else break;
  }
  // 1st case
  if((s.length()+t.length()-2*commonLength)>k){
            return "No";
  } else if((s.length()+t.length()-2*commonLength)%2==k%2){
      return "Yes";
  } else if((s.length()+t.length()-k)<0){
      return "Yes";
  } else{
      return "No";
  }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
