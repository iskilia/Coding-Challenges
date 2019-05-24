#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
// in a matrix, the maximum number of hourglasses is equal to (numRows -
// 2)*(numCols - 2)
int hourglassSum(vector<vector<int>> arr) {
  int numRows, numCols;
  numRows = arr.size();
  if (numRows < 3) {
    return -1;
  }
  numCols = arr[0].size();
  if (numCols < 3) {
    return -1;
  }
  int maxSum = INT_MIN;
  for (int i = 0; i < numRows - 2; i++) {
    for (int j = 0; j < numCols - 2; j++) {
      int sum = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) +
                (arr[i + 1][j + 1]) +
                (arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
      maxSum = max(maxSum, sum);
    }
  }
  return maxSum;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);

  fout << result << "\n";

  fout.close();

  return 0;
}
