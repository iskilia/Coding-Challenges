#include <bits/stdc++.h>
#include <string>
using namespace std;

#define for(i,a,b) for(int i = a; i < b; i++)

int r, c, n;

vector<string> init;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

vector<string> all0(){
  return vector<string>(R, string(C, 'O'));
}

vector<string> explore(vector<string> vs) {
	vector<string> ret = allO();

	for(i, 0, r) for(j, 0, c) if (vs[i][j] == 'O') {
		ret[i][j] = '.';
		for(k, 0, 4) {
			int ii = i + dx[k];
			int jj = j + dy[k];
			if (ii < 0 || R <= ii) continue;
			if (jj < 0 || C <= jj) continue;
			ret[ii][jj] = '.';
		}
	}

	return ret;
}

int main(){
  cin >> r >> c >> n;
  for(i, 0, r){
    string s;
    cin >> s;
    init.push_back(s);
  }
  if(n % 2 == 0){
    vector<string> vs = all0();
    for(i, 0, r){
      string temp = vs[i];
      cout << temp << endl;
    }
    return 0;
  }

  if(n == 1){
    for(i, 0, r){
      cout << init[i] << endl;
    }
    return 0;
  }

  vector<string> next = denonate(init);
	vector<string> after_next = denonate(next);

  n %= 4;

  if(n == 1){
    for(i, 0, r) cout << after_next[i] << endl;
  } else {
    for(i, 0, r) cout << next[i] << endl;
  }
  return 0;
}
