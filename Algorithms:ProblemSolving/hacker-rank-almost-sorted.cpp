#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
  // find swap candidates, swap and check if sorted
  int n = arr.size();
  vector<int> sorted(arr.size());
  for(int i = 0; i < arr.size(); i++) sorted[i] = arr[i];
  sort(sorted.begin(), sorted.end());
  vector<int> diff;
   for (int i=0;i<n;i++)
       if (sorted[i]!=arr[i])
           diff.push_back(i);
   if (diff.size()==0)
       printf("yes\n");
   else if (diff.size()==2)
       printf("yes\nswap %d %d\n",diff[0]+1,diff[1]+1); //Index starts at 1!!!
   else //Let's try reverse it!
   {
       int st = diff[0], ed = diff[diff.size()-1];
       while (st<ed)
       {
           swap(arr[st],arr[ed]);
           st++;
           ed--;
       }
       int flag=1;
       for (int i=0;i<n;i++)
           if (sorted[i]!=arr[i])
           {
               printf("no\n");
               return;
           }
       printf("yes\nreverse %d %d\n",diff[0]+1,diff[diff.size()-1]+1); //Index starts at 1!!!
   }
}

int main()
{
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

    almostSorted(arr);

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
