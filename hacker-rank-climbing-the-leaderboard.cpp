/* Climbing the leaderboard - Hackerrank */
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
   int n, m, leaderboard_score, alice_score;
   cin >> n;
   stack<int> scores;
   for (int i = 0; i < n; ++i) {
     cin >> leaderboard_score;
     if (scores.empty() || scores.top() != leaderboard_score) scores.push(leaderboard_score);
   }
   cin >> m;
   for (int i = 0; i < m; ++i) {
     cin >> alice_score;
     while (!scores.empty() && alice_score >= scores.top()) scores.pop();
     cout << scores.size() + 1 << endl;
   }
   return 0;
}
