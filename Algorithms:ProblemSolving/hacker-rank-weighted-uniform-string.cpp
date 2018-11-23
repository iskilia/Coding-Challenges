#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> answers;
    unordered_set<int> numSet;
    int lastAlphaNum = 0;
    int contigiousString = 1;
    for(int i = 0; i < s.length(); i++){
        int alphaNum = s[i] - 'a' + 1;
        if(alphaNum == lastAlphaNum){
            contigiousString++;
        } else {
            contigiousString = 1;
            lastAlphaNum = alphaNum;
        }
        int num = (alphaNum) * contigiousString;
        numSet.insert(num); 
    }

    for(int j = 0; j < queries.size(); j++){
        if(numSet.find(queries[j]) != numSet.end()){
            answers.push_back("Yes");
        } else {
            answers.push_back("No");
        }
    }
    return answers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
