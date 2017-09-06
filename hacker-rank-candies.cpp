/* Candies - HackerRank */
#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000
typedef long long ll;
ll store[MAX];
int students[MAX];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        memset(arr,0,sizeof(Students));
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
                 cin>>Students[i];
        dp[0]=1;
        for(int i=1;i<n;i++){
                if(Students[i]>Students[i-1])
                           store[i] = store[i-1]+1; // if right person has more rating he gets extra candy
                else if(Students[i] <= Students[i-1])
                         store[i] = 1;			// else he gets 1 candy
        }
        /* This maintains the condition, if left person has higher rating then he will be awarded one more candy  */
        /* max is used because if mid element has max rating his candy should be greater than both left and rights guys*/
        for(int i=n-2;i>=0;i--){
                if(Students[i] > Students[i+1])
                           store[i] = max(store[i],store[i+1]+1);
        }
        ll Num_candies = 0;
        for(int i=0;i<n;i++){
                 Num_candies += store[i];
        }
        cout<< Num_candies <<endl;
    return 0;
}
