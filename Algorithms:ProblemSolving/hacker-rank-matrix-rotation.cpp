#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int m, int n, int r) {
    int numRings = min(m,n)/2;
    for(int i = 0; i < numRings; i++){
      int numRotations =  r % (2*(m + n - 4*i) - 4);
      for(int rot = 0; rot < numRotations; rot++){
        // Rotate top row first
        for(int j = i; j < n - i - 1; j++){
          int tmp = matrix[i][j];
          matrix[i][j] = matrix[i][j+1];
          matrix[i][j+1] = tmp;
        }
        // rotate right column
        for(int j = i; j < m - i - 1; j++){
          int tmp = matrix[j][n-i-1];
		      matrix[j][n-i-1] = matrix[j+1][n-i-1];
	        matrix[j+1][n-i-1] = tmp;
        }

        // rotate bottom row
        for(int j = n-i-1; j > i; j--){
          int tmp = matrix[m-i-1][j];
		      matrix[m-i-1][j] = matrix[m-i-1][j-1];
		      matrix[m-i-1][j-1] = tmp;
        }

        // finally rotate left column
        for(int j = m-i-1; j > i + 1; j--){
          int tmp = matrix[j][i];
				  matrix[j][i] = matrix[j-1][i];
				  matrix[j-1][i] = tmp;
        }
      }
    }

    for(int k = 0; k < matrix.size(); k++){
      for(int l = 0; l < matrix[k].size(); l++){
        cout << matrix[k][l] << " ";
      }
      cout << endl;
    }

}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, m, n, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
