#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



// Complete the friendCircles function below.
// Was thinking BFS or DFS
// Runtime: O(n+m) where n is the number of people and m is the number of Y
// Space: O(n) q can be up to n size, and visited as well
int friendCircles(vector<string> friends) {
    int count = 0;
    int numFriends = friends.size();
    queue<int> q;
    vector<bool> visited(numFriends, false);
    for (int i = 0; i < numFriends; ++i) {
      if (visited[i])
        continue;
      q.push(i);
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        visited[t] = true;
        for (int j = 0; j < numFriends; ++j) {
          if (friends[t][j] == 'N' || visited[j])
            continue;
          q.push(j);
        }
      }
      count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string friends_count_temp;
    getline(cin, friends_count_temp);

    int friends_count = stoi(ltrim(rtrim(friends_count_temp)));

    vector<string> friends(friends_count);

    for (int i = 0; i < friends_count; i++) {
        string friends_item;
        getline(cin, friends_item);

        friends[i] = friends_item;
    }

    int res = friendCircles(friends);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
