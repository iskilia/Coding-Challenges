/* Cat Jogging - HackerRank */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <set>

using namespace std;

const int MAXN = 50000 + 10;

vector<int> adj[MAXN], adj_big[MAXN];
int n, m, ans[5], wn, w[MAXN], x, y;
int am[MAXN][MAXN / 30 + 10];
long long ans4;

inline bool exists_edge (int x, int y) {
	return ((am[x][y / 30] & (1 << (y % 30))) > 0);
}

const int MAX_NUM_BIGCAT_NODES = 4000;

int p[MAX_NUM_BIGCAT_NODES][MAX_NUM_BIGCAT_NODES], big_index[MAXN], big_nodes, q[MAX_NUM_BIGCAT_NODES][MAX_NUM_BIGCAT_NODES];

void count_4cliques () {
	int threshold = (int)exp(log(n * 1.0) / 3.0);
	for(int i = 1; i <= n; i++) if (adj[i].size() >= threshold)
		big_index[i] = ++big_nodes;
	for(int i = 1; i <= n; i++) for(int j = 0; j < adj[i].size(); j++) {
		if (big_index[adj[i][j]])
			adj_big[i].push_back(adj[i][j]);
	}
	// 4 big nodes
	long long ans_4big = 0;
	for(int i = 1; i <= n; i++) if (big_index[i]) for(int j = 0; j < adj_big[i].size(); j++) {
		int x = big_index[i];
		int xy = adj_big[i][j];
		for(int k = 0; k < adj_big[xy].size(); k++) {
			int z = big_index[adj_big[xy][k]];
			if (z && z != x)
				ans_4big += p[x][z]++;
		}
	}
	// 3 big nodes
	long long ans_3big = 0;
	for(int i = 1; i <= n; i++) if (!big_index[i]) {
		for(int j = 0; j < adj_big[i].size(); j++) {
			int x = big_index[adj_big[i][j]];
			for(int k = j + 1; k < adj_big[i].size(); k++) {
				int y = big_index[adj_big[i][k]];
				ans_3big += p[x][y];
			}
		}
	}
	// 2 big nodes lie diagonally
	long long ans_2big_diagonal = 0;
	for(int i = 1; i <= n; i++) if (!big_index[i]) {
		for(int j = 0; j < adj_big[i].size(); j++) {
			int x = big_index[adj_big[i][j]];
			for(int k = j + 1; k < adj_big[i].size(); k++) {
				int y = big_index[adj_big[i][k]];
				ans_2big_diagonal += q[min(x, y)][max(x, y)]++;
			}
		}
	}
	// 2 big nodes are connected
	long long ans_2big_conn = 0;
	for(int i = 1; i <= n; i++) if (!big_index[i]) {
		for(int j = 0; j < adj[i].size(); j++) if (!big_index[adj[i][j]]) {
			int y = adj[i][j];
			for(int a = 0; a < adj_big[i].size(); a++)
				for(int b = 0; b < adj_big[y].size(); b++) {
					int qa = adj_big[i][a];
					int qb = adj_big[y][b];
					ans_2big_conn += exists_edge(qa, qb);
				}
		}
	}
	// 1 big node OR 0 big nodes
	long long ans_1big = 0;
	long long ans_0big = 0;
	for(int i = 1; i <= n; i++) if (!big_index[i]) {
		for(int j = 0; j < adj[i].size(); j++) if (!big_index[adj[i][j]]) {
			int x = adj[i][j];
			for(int k = j + 1; k < adj[i].size(); k++) if (!big_index[adj[i][k]]) {
				int y = adj[i][k];
				for(int l = 0; l < adj[x].size(); l++) if (big_index[adj[x][l]] && adj[x][l] != i && adj[x][l] != y)
					ans_1big += exists_edge(adj[x][l], y);
				else if (adj[x][l] != i)
					ans_0big += exists_edge(adj[x][l], y);
			}
		}
	}
	ans4 = ans_4big / 4 + ans_3big + ans_2big_conn / 2 + ans_2big_diagonal + ans_1big + ans_0big / 4;
}

int main () {
    set<pair<int, int> > edges;
	cin >> n >> m;
    assert(1 <= n && n <= 50000);
    assert(1 <= m && m <= 100000);
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        assert(x != y);
        edges.insert(make_pair(min(x, y), max(x, y)));
		am[x][y / 30] |= (1 << (y % 30));
		am[y][x / 30] |= (1 << (x % 30));
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    assert(edges.size() == m);
	count_4cliques();
	cout << ans4 << endl;
	return 0;
}
