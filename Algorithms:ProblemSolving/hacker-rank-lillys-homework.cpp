#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

vector<string> split_string(string);

bool descCompare(int a,int b){
    return a>=b;
}
int helper(int currValue,int idx,vector<bool>&visit,int len,map<int,int>&indexMap,vector<int>&compareTo){
    if(visit[idx])
        return len-1;
    visit[idx] = true;
    return helper(compareTo[indexMap[currValue]],indexMap[currValue],visit,len+1,indexMap,compareTo);
}
int countNumberOfSwaps(int n,vector<int>&arr,vector<int>&compareTo){
    int numberOfSwaps = 0;
    map<int,int> indexMap; 
    for(int i=0;i<n;i++){
        indexMap[arr[i]]=i;
    }
    vector<bool> visit(n,false);
    for(int i = 0;i < n;i++)
        if(!visit[i])
            numberOfSwaps+=helper(compareTo[i],i,visit,0,indexMap,compareTo);
    return numberOfSwaps;
}
// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    vector<int> inc(arr);sort(inc.begin(),inc.end());
    vector<int> dec(arr);sort(dec.begin(),dec.end(),descCompare);
    return min(countNumberOfSwaps(arr.size(),arr,inc),countNumberOfSwaps(arr.size(),arr,dec));

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

    int result = lilysHomework(arr);

    fout << result << "\n";

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
