#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   unsigned int N, S, P, Q, mu, nu;
   const unsigned int exp = 1 << 31;
   cin >> N >> S >> P >> Q;
   unsigned int* a = new unsigned int[N];
   a[0] = S % exp;
   for (int i = 1; i < N; i++) {
       a[i] = (a[i-1] * P + Q) % exp;
   }
    for (int i = 0; i < N; i++) {
       if ((2*i)+1 > N-1) {
           // no cycle found -> N distinct values, output N, clean up and terminate execution
           cout << N;
           delete[] a;
           return 0;
       } else if(a[i] == a[(2*i)+1]) {
           // cycle detected, break loop to proceed with algorithm
           nu = i+1;
           break;
       }
   }
   // find first element of cycle
   for (int i = 0; i < N; i++) {
       if(a[i] == a[i+nu]) {
           mu = i;
           break;
       }
   }
   // find first reoccurence of first cycle element
   for (int i = mu+1; i < N; i++) {
       if(a[mu] == a[i]) {
           // number of elements up until first repeated cycle element = number of distinct values in sequence
           cout << i;
           break;
       }
   }
   // clean up, terminate execution
   delete[]a;
   return 0;
}
