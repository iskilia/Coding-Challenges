#include <bits/stdc++.h>

using namespace std;

// Complete the super_reduced_string function below.
string super_reduced_string(string s) {
  int i;
  while(i < static_cast< int > (s.size()-1)) {
  	if(i>-1 && s[i] == s[i+1]) {
  		s.erase(i,2);
  		i--;
  	} else
  		i++;
  }

  if(s.empty()) return "Empty String";
  else return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = super_reduced_string(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
