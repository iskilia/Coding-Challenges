// AUTHOR: iskilia
#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long num_queries,i,j,k,l,m;
    cin>>num_queries;
    //Iterate for the number of queries
    for(i = 0; i < num_queries; i++){
      long long n;
      cin >> n;
      //Create array
      long long nrc = 2*n;
      long long matrix[nrc][nrc];

      for(j = 0;j < nrc ;j++){
          for(k = 0;k < nrc;k++) cin>>matrix[j][k];
      }
      //calculation of the sum (comparing the corners of the corners
      long long sum = 0;
      for(l = 0; l < n; l++){
          for(m = 0; m < n ; m++){
              long long temp = matrix[l][m];
              temp = max(temp,max(matrix[nrc-l-1][m],matrix[l][nrc-m-1]));
              temp =  max(temp,matrix[nrc-l-1][nrc-m-1]);
              sum += temp;
          }
      }
      cout<<sum<<endl;
    }

}
