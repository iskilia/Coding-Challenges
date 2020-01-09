#include <iostream> 
using namespace std; 
  
// Returns count of possible paths to reach cell at row 
// number m and column number n from the topmost leftmost 
// cell (cell at 1, 1)
int numberOfPaths(int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    int count[n][m];

    // Setting up base cases
    for(int i = 0; i < n; i++){
        count[i][0] = 1;
    }

    for(int j = 0; j < m; j++){
        count[0][j] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            count[i][j] = count[i-1][j] + count[i][j-1];
        }
    }

    return count[n-1][m-1];
}

int main() 
{ 
    cout << numberOfPaths(5, 5) << endl; 
    cout << numberOfPaths(2, 2) << endl; 
    cout << numberOfPaths(3, 3) << endl; 
    cout << numberOfPaths(2, 3) << endl; 
    return 0; 
} 