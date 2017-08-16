/* Flipping Bits - Hackerrank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    unsigned int temp,out;
    unsigned int mask = 0xFFFFFFFF;
    cin >> T;
    for(int i = 0; i < T; i++){
      cin >> temp;
      out = temp ^ mask;
      cout << out << endl;
    }
    return 0;
}
