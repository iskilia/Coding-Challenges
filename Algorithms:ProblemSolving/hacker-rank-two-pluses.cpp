#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

struct Plus {
  int center_row, center_col, stretch, area;
};
// Complete the twoPluses function below.
vector<int> optimizeResults(vector<Plus> valid_areas){
  vector<int> results;
  int s = valid_areas.size();
  Plus a, b;
  for (int i = 0; i < s; i++) {

      a = valid_areas[i];

      for (int j = i+1; j < s; j++) {

          b = valid_areas[j];

          bool row, arow, col, acol;
          row = b.center_row < a.center_row;
          arow = b.center_row > a.center_row;

          col = b.center_col < a.center_col;
          acol = b.center_col > a.center_col;

          if (row) {
              if (col) {
                  if ((b.stretch + b.center_row >= a.center_row && a.center_col - a.stretch <= b.center_col)
                      || (b.center_col + b.stretch >= a.center_col && a.center_row - a.stretch <= b.center_row)) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } else if (acol) {
                  if ((b.stretch + b.center_row >= a.center_row && a.center_col + a.stretch >= b.center_col)
                      || (b.center_col - b.stretch <= a.center_col && a.center_row - a.stretch <= b.center_row)) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } else {
                  if (b.stretch + b.center_col >= a.center_col - a.stretch) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              }
          } else if (arow) {
              if (col) {
                  if ((b.center_row - b.stretch <= a.center_row && a.center_col - a.stretch <= b.center_col)
                      || (b.center_col + b.stretch >= a.center_col && a.center_row + a.stretch >= b.center_row)) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } else if (acol) {
                  if ((b.center_row - b.stretch <= a.center_row && a.center_col + a.stretch >= b.center_col)
                      || (b.center_col - b.stretch <= a.center_col && a.center_row + a.stretch >= b.center_row)) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } else {
                  if (b.center_col - b.stretch <= a.center_col + a.stretch) {
                      continue;
                  } else {
                      results.push_back(a.area * b.area);
                      break;
                  }
              }
          } else {
              if (col) {
                  if (b.stretch + b.center_col < a.center_col - a.stretch) {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } else if (acol) {
                  if (b.center_col - b.stretch > a.center_col + a.stretch) {
                      results.push_back(a.area * b.area);
                      break;
                  }
              } // else continue
          }
      }
  }

  return results;
}

vector<Plus> getValidAreas(vector<vector<bool>> grid, int n, int m){
  vector<Plus> ret;
  vector<int> arr;
  int i, j, up, down, right, left, tmp_i, tmp_j, max_stretch;
  for(i = 1; i < n - 1; i++){
    for(j = 1; j < m - 1; j++){
      if(!grid[i][j]) continue;
      up = down = left = right = 0;
      tmp_i = i-1;
      while(tmp_i >= 0 && grid[tmp_i--][j]) up++;
      tmp_i = i+1;
      while(tmp_i < n && grid[tmp_i++][j]) down++;
      tmp_j = j+1;
      while(tmp_j < m && grid[i][tmp_j++]) right++;
      tmp_j = j-1;
      while(tmp_j >= 0 && grid[i][tmp_j--]) left++;
      arr = {up,down,left,right};
      for(max_stretch = *std::min_element(arr.begin(), arr.end()); max_stretch >= 0; max_stretch--){
        ret.push_back({i, j, max_stretch,max_stretch*4+1});
      }
    }
  }

  return ret;
}

vector<vector<bool>> parseToVector(int n, int m){
  char in;
  vector<vector<bool>> retGrid(n, vector<bool>(m));
  for(auto & row : retGrid){
    for(auto element : row){
      cin >> in;
      element = in == 'G';
    }
  }
  return retGrid;
}

bool compare (Plus l, Plus r){return l.area > r.area;}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> grid = parseToVector(n,m);
  vector<Plus> valid_areas = getValidAreas(grid, n, m);
  sort(valid_areas.begin(), valid_areas.end(), compare);
  cout << valid_areas.size() << endl;
  vector<int> results = optimizeResults(valid_areas);
  cout << *max_element(results.begin(), results.end()) << endl;
  return 0;
}
