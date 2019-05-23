#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#define MAXN 30010
#define INF 1000000000

using namespace std;

const int maxlen = 100010;
const int maxlog = 21;
int S[maxlen];
int lg[maxlen], tmp[2000];
struct SuffixArray {
    int rank[maxlen], SA[maxlen], h[maxlen], D[maxlen];
    int n, dep, count_rank[maxlen],f[maxlog][maxlen], rmq[maxlog][maxlen];
    void Build() {
        for (int len = 1; len < n; len <<= 1) {
            fill(count_rank, count_rank + 1 + n, 0);
            for (int i = 1; i <= n; i++)
                ++count_rank[rank[SA[i]+len]];
            for (int i = 1; i <= n; i++)
                count_rank[i] += count_rank[i-1];
            for (int i = n; i > 0; i--)
                D[count_rank[rank[SA[i]+len]]--] = SA[i];
            fill(count_rank, count_rank+1+n, 0);
            for (int i = 1; i <= n; i++)
                ++count_rank[rank[SA[i]]];
            for (int i = 1; i <= n; i++)
                count_rank[i] += count_rank[i-1];
            for (int i = n; i > 0; i--)
                SA[count_rank[rank[D[i]]]--] = D[i];
            copy(rank, rank+1+n, D);
            rank[SA[1]]=1;
            for (int i = 2; i <= n; i++)
                if (D[SA[i]] != D[SA[i-1]] ||
                    D[SA[i]+len] != D[SA[i-1] + len])
                    rank[SA[i]] = rank[SA[i-1]] + 1;
                else
                    rank[SA[i]] = rank[SA[i-1]];
            if (rank[SA[n]] == n) break;
        }
    }

    int strsuf(int *p, int *q) {
        int ret = 0;
        for (; *p == *q; ++p, ++q, ++ret);
        return ret;
    }

    void CalcHeight() {
        for (int i = 1; i <= n; i++) {
            if (rank[i] == 1)
                h[i] = 0;
            else if (i == 1 || h[i-1] <= 1)
                h[i] = strsuf(S+i, S+SA[rank[i]-1]);
            else
                h[i] = strsuf(S+i+h[i-1]-1, S+SA[rank[i]-1]+h[i-1]-1) + h[i-1]-1;
            f[0][rank[i]] = h[i];
            rmq[0][i] = SA[i];
        }
        dep = 1;
        for (int len = 1; len*2<=n; len<<=1,dep++) {
            for (int i = 1; i +len*2-1 <= n; i++) {
                f[dep][i] = min(f[dep-1][i], f[dep-1][i+len]);
                rmq[dep][i] = min(rmq[dep-1][i], rmq[dep-1][i+len]);
            }
        }
    }

    void init(int _n) {
        n = _n;
        fill(rank,rank+2*n+2,0);
        memset(tmp,0,sizeof(tmp));
        for (int i = 1; i <= n; i++)
            ++tmp[S[i]];
        for (int i = 1; i < 2000; i++) tmp[i] += tmp[i-1];
        for (int i = n; i > 0; i--)
            SA[tmp[S[i]]--] = i;
        rank[SA[1]]=1;
        for (int i = 2; i <= n; i++)
            if (S[SA[i]] != S[SA[i-1]])
                rank[SA[i]] = rank[SA[i-1]] + 1;
            else
                rank[SA[i]] = rank[SA[i-1]];
        Build();
        CalcHeight();
        //for (int i = 1; i <= n; i++)
        //    cerr << i << ": " << SA[i] << endl;
        //for (int i = 1; i <= n; i++)
        //    cerr << i << ": " << rank[i] << endl;
    }

    inline int lcp(int a, int b) {
        if (a == b) return n - a + 1;
        a = rank[a], b = rank[b];
        if (a > b) swap(a,b);
        int d = lg[b - a];
        if ((1 << d) == (b - a)) return f[d][a+1];
        else return min(f[d][a+1], f[d][b-(1<<d)+1]);
    }

    inline int RMQ(int a, int b) {
        if (a > b) swap(a,b);
        int d = lg[b - a + 1];
        return min(rmq[d][a], rmq[d][b-(1<<d)+1]);
    }

    inline int findlo(int a, int plen) {
        int lo = 0, hi = a, mid;
        while (hi - lo > 1) {
            mid = (hi + lo) / 2;
            if (lcp(SA[a],SA[mid]) >= plen) hi = mid;
            else lo = mid;
        }
        return hi;
    }

    inline int findhi(int a, int plen) {
        int lo = a, hi = n+1, mid;
        while (hi - lo > 1) {
            mid = (hi + lo) / 2;
            if (lcp(SA[a],SA[mid]) >= plen) lo = mid;
            else hi = mid;
        }
        return lo;
    }
} SA;

int n,a,b;
string s;
int dp[MAXN];

int main() {
    for (int i = 2; i < maxlen; i++)
        lg[i] = lg[i >> 1] + 1;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> s;

        for (int i = 0; i < n; i++)
            S[i+1] = s[i]-'a'+1;
        S[n+1] = 0;

        SA.init(n+1);
        //for (int i = 1; i <= n+1; i++) cerr << SA.SA[i] << ' '; cerr << endl;

        for (int i = 1; i <= n; i++)
            dp[i] = INF;

        //cerr << "i mid : l r : j" << endl;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i], dp[i-1] + a);

            int lo = 0, hi = i+1, mid;
            while (hi - lo > 1) {
                mid = (lo + hi) / 2;
                int l = SA.findlo(SA.rank[i],mid);
                int r = SA.findhi(SA.rank[i],mid);
                int j = SA.RMQ(l,r);
                //cerr << i << ' ' << mid << " : " << l << ' ' << r << " : " << j << endl;
                if (j + mid - 1 < i) lo = mid;
                else hi = mid;
            }

            dp[i+lo-1] = min(dp[i+lo-1], dp[i-1] + b);

            //cerr << i << ": " << lo << endl;
        }

        cout << dp[n] << '\n';
    }
}