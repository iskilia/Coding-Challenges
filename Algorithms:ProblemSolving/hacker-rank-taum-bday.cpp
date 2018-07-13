#include <bits/stdc++.h>
typedef  unsigned long long ull;
using namespace std;


// Complete the taumBday function below.
ull taumBday(ull b, ull w, ull bc, ull wc, ull z) {
  ull x = (wc + z < bc) ? wc + z : bc;
  ull y = (bc + z < wc) ? bc + z : wc;
  return b*x + w*y;
}

int main()
{

    int t;
    cin >> t;
    unsigned long long b,w,bc,wc,z;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        cin >> b >> w;
        cin >> bc >> wc >> z;
        ull result = taumBday(b, w, bc, wc, z);
        cout << result << endl;
    }
    return 0;
}
