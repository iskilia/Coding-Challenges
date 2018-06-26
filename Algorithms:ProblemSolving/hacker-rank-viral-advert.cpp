#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
  int m = 5;
  int interested_ppl = 0, count = 0;
  for(int i = 0; i < n; i++){
      interested_ppl = (m/2);
      count += interested_ppl;
      m = interested_ppl * 3;
  }
  return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
