#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // declare variables
    int num_queries,nStart,nEnd;
    cin >> num_queries;
    for(int i = 0; i < num_queries; i++){
         scanf("%u %u", &nStart, &nEnd);
         unsigned int nWalk = (nEnd - nStart);
         unsigned int nMask = 1;
         while (nWalk){
            nWalk >>= 1;
            nMask <<= 1;
         }
         nMask = nMask - 1;
         printf("%u\n", (nStart & ~nMask & nEnd));
    }
    return 0;
}
