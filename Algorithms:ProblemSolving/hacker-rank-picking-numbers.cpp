/* Picking Numbers - Hackerrank */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n,k,max;
    cin >> n;
    vector<int> a(n);
    a[100] = 0;
    max = 0;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> k;
       a[k]++;
    }
    for(int i = 0; i < n-1;i++){
      if(a[i]+a[i+1] > max) max = a[i]+a[i+1];
    }
    cout << max << endl;
    return 0;
}
