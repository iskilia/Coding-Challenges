/* Counting Game - Hackerrank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numTestcases;
    cin >> numTestcases;
    for (int i = 0; i < numTestcases; i++){
        unsigned long long N;
        int count = 0;
        cin >> N;
        N--;
        while(N) {
            N &= (N-1);
            count++;
        }
        cout << (count & 1 ? "Louise" : "Richard") << endl;
    }
    return 0;
}
// Richard wins print "Richard"
// Louise wins print "Louise"
// Louise go first
