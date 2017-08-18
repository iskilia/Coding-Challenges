/* Queens On Board - HackerRank */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int N, M; // Number of rows and columns.
char grid[50][5]; // Character representation of the grid.
int valid_configs[50][1 << 5]; // Valid configurations for row i (up to 2 ^ 5 of them).
int number_of_valid[50]; // Number of valid configurations in row i.
int bitmasks[50]; // Array of N bitmasks containing 111 for each M.
int memo[50][1 << 15]; // Number of solutions for a given row and bitmask.
int memo2[1 << 15]; // The next bitmask, given a particular bitmask.

// Get the next bitmask with queen attack vectors accounted for.
int spread(int mask)
{
  if (memo2[mask] != -1) return memo2[mask]; // Solutions been found before, use it.
  int nmask = 0;
  // For each square
  for (int i = 0; i < M; i++) {
    // If a left-angling attack vector exists and we're not at the left edge,
    // extend it into the left-diagonal square.
    if (mask & 1 << 3 * i && i > 0) {
      nmask |= 1 << 3 * i - 3;
    }
    // If a vertical attack vector exists, extend it into the square below.
    if (mask & 1 << 3 * i + 1) {
      nmask |= 1 << 3 * i + 1;
    }
    // If a right-angling attack vector exists and we're not at the right edge,
    // extend it into the right-diagonal square.
    if (mask & 1 << 3 * i + 2 && i + 1 < M) {
      nmask |= 1 << 3 * i + 5;
    }
  }
  return memo2[mask] = nmask;
}

// Solve for row x, with a mask for squares that are blocked by earlier queens.
int solve (int x, int mask)
{
  if (x == N) return 1; // We've reached the end of a solution, so return.
  mask &= ~bitmasks[x]; // Adjust the mask for squares that are already blocked
  if (memo[x][mask] != -1) return memo[x][mask]; // If we've already solved this, return the result
  int ret = 0; // If not, count solutions.
  // For each configuration of this row
  for (int i = 0; i < number_of_valid[x]; i++) {
    // If we haven't tried all configurations yet
    if (!(valid_configs[x][i] & mask)) {
      ret += solve(x + 1, spread(valid_configs[x][i] | mask)); // Try the next row, with rows blocked by queens masked out
      if(ret >= MOD) ret -= MOD; // Don't let the number get too big.
    }
  }
  return memo[x][mask] = ret;
}

int solve()
{
  // For each row in N
  for (int i = 0; i < N; i++) {
    bitmasks[i] = 0;
    int cmask = 0;
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == '#') {
        cmask |= 1 << j; // Create bitmask with 111111111111111 (for M==5)
        bitmasks[i] |= 7 << 3 * j;
      }
    }

    number_of_valid[i] = 0;
    // For each 2 ^ M permutations of queens on this row
    for (int j = 0; j < 1 << M; j++) {
      // If the queen is not on a #
      if ((j & cmask) == 0) {
        bool valid = true;
        // For each column in M
        for (int k = 0; k < M; k++) {
          // If a queen is in that column, and another queen is on the same row
          // before another #, then that position isn't valid.
          if (j & 1 << k) {
            for (int kk = k + 1; kk < M && grid[i][kk] != '#'; kk++) {
              if (j & 1 << kk) {
                valid = false;
              }
            }
          }
        }
        if (!valid) continue;

        // If this is a valid configuration of queens for this row, create a
        // bitmask with 111 where a queen is. Add it to the good matrix at row i
        // and increment the size of that row (number_of_valid).
        int sp = 0;
        for (int k = 0; k < M; k++) {
          if (j & 1 << k) {
            sp |= 7 << 3 * k;
          }
        }
        valid_configs[i][number_of_valid[i]] = sp;
        number_of_valid[i]++;
      }
    }
  }

  // Initialize memoization tables to -1 for each entry.
  memset(memo,255,sizeof memo);
  memset(memo2,255,sizeof memo2);
  // Solve recursively.
  return solve(0,0);
}

int main()
{
  int test_cases;
  cin >> test_cases;
  for(int i = 0; i < test_cases; i++){
    cin >> N >> M;
    // Initialize board.
    for (int i = 0;i < N;i++) cin >> grid[i];
    int ret = solve();
    ret = (ret - 1 + MOD) % MOD;
    cout << ret << endl;
  }
  return 0;
}
