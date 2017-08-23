/* Misere Nem - HackerRank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(int stones[], int size){
    if(size == 1){
      return (stones[0] > 1) ? true : false;
    }
    int totalStones = stones[0];
    int xorVal = stones[0];
    for(int s = 1; s < size; s++){
        totalStones += stones[s];
        xorVal ^= stones[s];
    }
    if(totalStones == size) return (totalStones % 2 == 0) ? true : false;

    return (xorVal > 0) ? true : false;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_testcases;
    cin >> num_testcases;
    for(int i = 0; i < num_testcases; i++){
      int n;
      cin >> n;
      int stones[n];
      for(int j = 0; j < n; j++) cin >> stones[j];
      bool result = solve(stones,n);
      if(result) cout << "First" << endl;
      else cout << "Second" << endl;
    }
    return 0;
};
