#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        if (k == 0) {
            for (int j = 1; j <= n; j++)
                cout << j << " ";
            cout << endl;
        } else if (n % (2 * k) != 0) {
            cout << -1 << endl;
        } else {
          vector<int> perm(n + 1);
          for (int j = 1; j <= n; j += 2 * k) {
              for (int l = j; l < j + k; ++l) {
                  perm[l] = l + k;
                  perm[l+k] = l;
              }
          }
          for (int j = 1; j <= n; ++j)
              cout << perm[j] << " ";
          cout << endl;
        }
    }
    return 0;
}
