#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    // Read input
    int arr1Len, arr2Len;
    cin>>arr1Len>>arr2Len;
    int *arr1 = new int[arr1Len];
    int *arr2 = new int[arr2Len];
    for(int i = 0; i < arr1Len; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i < arr2Len; i++) {
        cin>>arr2[i];
    }
    // Setup DP 
    int **matrix = new int*[arr1Len+1];
    for(int i = 0; i <= arr1Len; i++) {
        matrix[i] = new int[arr2Len+1];
        for(int j = 0; j <= arr2Len; j++) {
            matrix[i][j] = 0;
        }
    }
    // Main algorithm
    for(int i = 1; i <= arr1Len; i++) {
        for(int j = 1; j <= arr2Len; j++) {
            if(arr1[i-1] == arr2[j-1]) {
                // Property 1
                matrix[i][j] = matrix[i-1][j-1] + 1;
            } else {
                // Property 2
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    // Read off solution, size of lcs is matrix[arr1Len][arr2Len]
    int *lcs = new int[matrix[arr1Len][arr2Len]];
    int count = matrix[arr1Len][arr2Len];
    int i = arr1Len, j = arr2Len;
    while(count > 0) {
        if(matrix[i-1][j] == matrix[i][j]) {
            // Value came from smaller arr1
            i--;
        } else if(matrix[i][j-1] == matrix[i][j]) {
            // Value came from smaller arr2
            j--;
        } else {
            // Value came from the letter at the current index
            lcs[count-1] = arr1[i-1];
            i--;
            j--;
            count--;
        }
    }
    for(int i = 0; i < matrix[arr1Len][arr2Len]; i++) {
        cout<<lcs[i]<<" ";
    }
    return 0;
}
