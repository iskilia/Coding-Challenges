/* Roads and Libraries - HackerRank */
#include <stdio.h>
#include <iostream>
#include <climits>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <int, int>
#define plp pair <int, pll >
#define pb push_back

vector <ll> ed[100010];

bool vis[100010];

ll sum;

void dfs(ll n)
{
    sum++;
    vis[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll v = ed[n][i];
        if (vis[v] == 0)
        {
            dfs(v);
        }
    }
}


int main ()
{
  //  freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, t, i, j, k, x, y, z, ans, q, m, n, p;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);
        sl(m);
        sl(p);
        sl(q);

        memset(vis, 0, sizeof(vis));

        for (i = 1; i <= n; i++)
        {
            ed[i].clear();
        }

        for (i = 1; i <= m; i++)
        {
            sl(x);
            sl(y);

            ed[x].pb(y);
            ed[y].pb(x);
        }

        ans = 0;

        for (i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                sum = 0;
                dfs(i);

                ans += min(p + q*(sum - 1), p*sum);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
