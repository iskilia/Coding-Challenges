#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e6 + 10;
const int XX = 1e5 + 10;
const int C = 26;

int n, qq, pos[MAXN], nxt[MAXN][C], f[MAXN], sz, val[MAXN];

int insert(string &t) {
  int cur = 0;
  for (char c : t) {
    if (!nxt[cur][c - 'a'])
      nxt[cur][c - 'a'] = ++sz;
    cur = nxt[cur][c - 'a'];
  }
  return cur;
}

int q[MAXN], sub[MAXN], st[MAXN], ft[MAXN], cur[MAXN];
void aho() {
  int h = 0, t = 0;
  for (int w = 0; w < C; w++)
    if (nxt[0][w])
      q[t++] = nxt[0][w];
  while (h < t) {
    int v = q[h++];
    for (int w = 0; w < C; w++)
      if (nxt[v][w]) {
        f[nxt[v][w]] = nxt[f[v]][w];
        q[t++] = nxt[v][w];
      } else
        nxt[v][w] = nxt[f[v]][w];
  }

  fill(sub, sub + sz + 1, 1);
  for (int i = t - 1; ~i; i--)
    sub[f[q[i]]] += sub[q[i]];
  ft[0] = sz + 1;
  cur[0] = 1;
  for (int j = 0; j < t; j++) {
    int i = q[j];
    st[i] = cur[f[i]];
    cur[f[i]] = ft[i] = st[i] + sub[i];
    cur[i] = st[i] + 1;
  }
}

ll fen[MAXN], ans[MAXN];
vector<pair<pair<int, int>, int>> vec[XX];
void add(int v, int val) {
  for (v++; v < MAXN; v += v & -v)
    fen[v] += val;
}
ll get(int v) {
  ll ret = 0;
  for (; v; v -= v & -v)
    ret += fen[v];
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    pos[i] = insert(t);
  }
  for (int i = 0; i < n; i++)
    cin >> val[i];
  aho();
  cin >> qq;
  for (int i = 0; i < qq; i++) {
    int l, r;
    string s;
    cin >> l >> r >> s, r++;
    int v = 0;
    for (char c : s) {
      v = nxt[v][c - 'a'];
      vec[l].push_back({{v, -1}, i});
      vec[r].push_back({{v, 1}, i});
    }
  }

  for (int i = 0; i < n; i++) {
    add(st[pos[i]], val[i]);
    add(ft[pos[i]], -val[i]);

    for (auto &x : vec[i + 1])
      ans[x.S] += get(st[x.F.F] + 1) * x.F.S;
  }

  ll mx = -1, mn = 1e18;
  for (int i = 0; i < qq; i++)
    mx = max(mx, ans[i]), mn = min(mn, ans[i]);
  cout << mn << " " << mx << "\n";
  return 0;
}