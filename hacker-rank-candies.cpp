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
long long dp[MAX];
int arr[MAX];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        memset(arr,0,sizeof(arr));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
                 cin>>arr[i];
        dp[0]=1;
        for(int i=1;i<n;i++){
                if(arr[i]>arr[i-1])
                           dp[i]=dp[i-1]+1; // if right person has more rating he gets extra candy
                else if(arr[i]<=arr[i-1])
                         dp[i]=1;			// else he gets 1 candy
        }
        /* This maintains the condition, if left person has higher rating then he will be awarded one more candy  */
        /* max is used because if mid element has max rating his candy should be greater than both left and rights guys*/
        for(int i=n-2;i>=0;i--){
                if(arr[i]>arr[i+1])
                           dp[i]=max(dp[i],dp[i+1]+1);
        }
        ll sum=0;
        for(int i=0;i<n;i++){
                 sum+=dp[i];
             //   cout<<dp[i]<<endl;
        }
        cout<<sum<<endl;
    return 0;
}
