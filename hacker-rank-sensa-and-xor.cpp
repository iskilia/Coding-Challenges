/* Bitwise AND Product - Hackerrank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test_cases, n;
    long int answer;
    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; i++){
      answer = 0;
      cin >> n;
      long int arr[n];
      for(int j = 0; j < n; j++){
        cin >> arr[j];
        if(j % 2 == 0){
          answer ^= arr[j];
        }
      }
      if(n % 2 == 0){
        cout << "0" << endl;
      } else {
        cout << answer << endl;
      }
    }
    return 0;
}
