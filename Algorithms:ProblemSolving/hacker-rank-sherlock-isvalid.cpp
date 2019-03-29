#include <bits/stdc++.h>
#include <string>
using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> letterCount(26,0);
    int n=s.size(),min_count=0,max_count=0;
    if(n == 1){
        return "YES";
    }
    for(int i=0;i<n;i++){
        letterCount[s[i]-'a']++;
    }
    letterCount.erase(remove(letterCount.begin(),letterCount.end(),0),letterCount.end());
    int max =*max_element(letterCount.begin(),letterCount.end());
    int min=*min_element(letterCount.begin(),letterCount.end());
    for(int i=0;i<letterCount.size();i++){
        if(letterCount[i]==max){
            max_count++;
        }
        else if(letterCount[i]==min){
            min_count++;
        }
    }
    if(max==min){
        return "YES";
    } else if(min_count + max_count != letterCount.size()){
        return "NO";
    } else if(min_count == 1 && min_count==1){
        return "YES";
    } else if(max_count==1 && max==min+1){
        return "YES";
    } else {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
