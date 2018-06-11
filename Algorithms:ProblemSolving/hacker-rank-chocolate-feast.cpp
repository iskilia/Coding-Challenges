/* Chocolate Feast - HackerRank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int num_chocolates = n/c;
        int num_wrappers = num_chocolates;
        int exchange_chocolates = num_wrappers/m;
        while(num_wrappers >= m){
          exchange_chocolates = exchange_chocolates + (num_wrappers/m + num_wrappers%m)/m;
          num_wrappers = num_wrappers/m;
        }
        cout << (num_chocolates + exchange_chocolates) << endl;
    }
    return 0;
}
