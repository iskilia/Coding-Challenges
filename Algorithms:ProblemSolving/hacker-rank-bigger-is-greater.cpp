#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
  if(w.empty() or w.size() == 1) return "no answer";

  int index_arr[ ] = {-1, -1};
  for(int j = w.size() -1; j > -1; j--){
    for(int i = j; i > -1; i--){
        if(w[i] < w[j] && i > index_arr[0]){
          index_arr[0] = i;
          index_arr[1] = j;
        }
    }
  }

  if(index_arr[0] == index_arr[1]) return "no answer";
  else{
    swap(w[index_arr[0]], w[index_arr[1]]);
    sort(w.begin() + index_arr[0] + 1, w.end(), less<int>());
    return w;
  }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
