/* Interval Selection - HackerRank*/
/* Author: @IsaacKilis*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool compare(const pair<int, int> left, const pair<int, int> right){
  return left.second < right.second;
}
int main(void){
   int test;
   cin >> test;

   for(int t = 0; t < test; t++){
      int N;
      cin >> N;
      vector<int> x;
      pair<int, int> arr[N];
      bool flag[N];
      for(int i = 0; i < N; i++){
        cin >> arr[i].first >> arr[i].second;
        if(arr[i].second < arr[i].first) swap(arr[i].second, arr[i].first);
        x.push_back(arr[i].second);
        flag[i] = 1;
      }
      sort(x.begin(), x.end());
      sort(arr, arr+N, compare);
      for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < N; j++){
          if(flag[j]){
            if(arr[j].first <= x[i] && arr[j].second >= x[i]){
              count++;
              if (count > 2) {
                  flag[j] = 0;
              }
            }
          }
        }
      }
      int result = 0;
      for(int i = 0; i < N; i++) result += flag[i];
      cout << result << endl;;
   }
   return 0;
}
