/* Sam and Substrings - HackerRank */
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
#include<iostream>
#include<string>

using namespace std;

const int MOD = 1000000007;
int state[200001];

void init()
{
	state[1] = 1;
	for (int i = 2; i <= 200000; i++)
		state[i] = ((long long)state[i - 1] * 10 + 1) % MOD;
}

int main()
{
	init();
	string num;
	cin >> num;
	int n = (int)num.size();
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int digit = num[i - 1] - '0';
		ans = ((long long)digit * i * state[n - i + 1] + ans) % MOD;
	}
	cout << ans << endl;
	return 0;
}
