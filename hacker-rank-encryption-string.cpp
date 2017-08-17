/* Encryption - Hackerrank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    // Declaring used variables
    int s_length, upper_bound, lower_bound, ans,r,c;
    //Defining the scope of the problem in variables
    s_length = (int)s.length();
    lower_bound = (int)sqrt(1.0*s_length);
    upper_bound = (int)ceil(sqrt(1.0*s_length));
    ans =  INT8_MAX;
    //Calculating the size of the grid
    for(int row = lower_bound; row <= upper_bound; row++){
      for (int col = row; col <= upper_bound; col++){
        if(row*col >= s_length && row * col < ans){
          ans = row*col;
          r = row;
          c = col;
        }
      }
    }
    //Printing out the encryption
    for(int i = 0; i < c; i++){
      for(int j = 0; j < r; j++){
        if(j*c + i < s_length){
          cout << s[j*c + i];
        }
      }
      cout << " ";
    }
    cout << endl;
    return 0;
}
