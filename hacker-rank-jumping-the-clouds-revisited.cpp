/* Jumping on Clouds Revisited - Hackerrank */
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
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int Energy = 100;
    int index = 0;
    int flag = 1;
    while(flag){
      index = (index + k) % n;
      Energy--;
      if(c[index] == 1) Energy -= 2;
      if(index == 0) flag = 0;
    }
    cout << Energy << endl;
    return 0;
}
