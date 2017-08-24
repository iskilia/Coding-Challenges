/* Roads in Hackerland - HackerRank */
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);


const int oo = 1e9, bpr = 1e9 + 7, N = 4e5 + 100;


struct edge {
	int cost, from, to;
};

inline bool operator < (const edge &a, const edge &b) {
	return a.cost < b.cost;
}

int Vertices[N];
vector <pair <int, int> > graph[N];
vector <edge> edges;
int sz[N];
ll ans[N];
int V, E;

inline int get_vertex (int x) {
	return Vertices[x] = ((x == Vertices[x]) ? x : get_vertex (Vertices[x]));
}

inline void Merge (int x, int y) {
	x = get_vertex (x), y = get_vertex (y);
	Vertices[x] = y;
}

inline void dfs (int v, int p = -1) {
	sz[v] = 1;
	for (auto to : graph[v]) {
		if (to.first == p)
			continue;
		dfs (to.first, v);
		sz[v] += sz[to.first];
		ans[to.second] += sz[to.first] * 1ll * (V - sz[to.first]);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> V >> E;

	for (int i=  1; i <= E; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		edges.push_back ({c, x, y});
	}

	for (int i = 1; i <= V; ++i)
		Vertices[i] = i;

	sort (edges.begin (), edges.end ());

	for (auto it : edges) {
		if (get_vertex (it.from) != get_vertex (it.to)) {
			graph[it.from].emplace_back (make_pair (it.to, it.cost));
			graph[it.to].emplace_back (make_pair (it.from, it.cost));
			Merge (it.to, it.from);
		}
	}

	dfs (1);


	int lst = 0;

	for (int i = 0; i + 1 < N; ++i) {
		ans[i + 1] += ans[i] / 2;
		ans[i] %= 2;
		if (ans[i])
			lst = i;
	}

	for (int i = lst; i >= 0; --i)
		cout << ans[i];

	return 0;
}
