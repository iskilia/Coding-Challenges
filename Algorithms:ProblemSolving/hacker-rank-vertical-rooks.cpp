/* Vertical Rooks - HackerRank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(int player1[], int player2[], int n){
    int xor_sum = 0;
    for(int i = 0; i < n; i++){
      xor_sum ^= abs(player1[i] - player2[i]) - 1;
    }
    return (xor_sum != 0) ? true : false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int player1[n], player2[n];
        for(int j = 0; j < n; j++) cin >> player1[j];
        for(int k = 0; k < n; k++) cin >> player2[k];
        if(solve(player1, player2, n)){
            cout << "player-2" << endl;
        } else {
            cout << "player-1" << endl;
        }
    }
    return 0;
}
