#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// O(nlogn) RT, O(n) Space
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    pair<int, int> arrPositions[n];
    for (int i = 0; i < n; i++){
        arrPositions[i].first = arr[i];
        arrPositions[i].second = i;
    }
    sort(arrPositions, arrPositions+n);
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] || arrPositions[i].second == i){
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while(!visited[j]){
            visited[j] = 1;
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0){
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
