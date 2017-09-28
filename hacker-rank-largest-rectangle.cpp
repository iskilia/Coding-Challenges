#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

long largestRectangle(vector <int> h) {
    // Complete this function
    long max_area = 0;
    stack<int> s;
    int top;
    long area_with_top;
    int i = 0;
    while(i < h.size()){
      if(s.empty() || h[s.top()] <= h[i]) s.push(i++);
      else{
        top = s.top();
        s.pop();
        area_with_top = (long)h[top] * (s.empty() ? i : i - s.top() - 1);
        max_area =  max(max_area, area_with_top);
      }
    }

    while(!s.empty()){
      top = s.top();
      s.pop();
      area_with_top = h[top] * (s.empty() ? i : i - s.top() - 1);
      max_area =  max(max_area, area_with_top);
    }

    return max_area;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}
