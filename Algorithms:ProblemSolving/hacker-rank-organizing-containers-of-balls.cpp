#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
  vector<int> RowSums(container.size(), 0); // Sum of rows in matrix
  vector<int> ColSums(container.size(), 0); // sum of columns in container
  int n = container.size();
  for(int r = 0; r < n; r++){
    for(int c = 0; c < n; c++){
      ColSums[r] += container[r][c];
      RowSums[r] += container[c][r];
    }
  }
  sort(RowSums.begin(), RowSums.end());
  sort(ColSums.begin(), ColSums.end());

  if(RowSums.size() != ColSums.size()) return "Impossible";
  for(int i = 0; i < RowSums.size(); i++){
    if(RowSums[i] != ColSums[i]) return "Impossible";
  }
  return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
