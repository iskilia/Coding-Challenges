#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
  vector<int> rows_to_replace, cols_to_replace;
  for(int i = 1; i < grid.size()-1; i++){
    for(int j = 1; j < grid.size()-1;j++){
      if(grid[i][j]-48 > grid[i-1][j]-48 &&
                  grid[i][j]-48 > grid[i+1][j]-48 &&
                  grid[i][j]-48 > grid[i][j-1]-48 &&
                  grid[i][j]-48 > grid[i][j+1]-48){
                    rows_to_replace.push_back(i);
                    cols_to_replace.push_back(j);
                  }

    }
  }
  assert(rows_to_replace.size() == cols_to_replace.size());
  for(int k = 0; k < rows_to_replace.size(); k++){
    grid[rows_to_replace[k]][cols_to_replace[k]] = 'X';
  }

  return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
