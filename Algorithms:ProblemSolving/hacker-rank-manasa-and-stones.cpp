#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
  vector<int> ret;
  int init = (n-1)*min(a,b);
  ret.push_back(init); // first possible stone
  int total = 0;
  while(total + init < (n-1) * max(a,b)){
    total += abs(b-a);
    ret.push_back(total+init);
  }
  return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
