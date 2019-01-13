#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    } else {
        bool flag = true;
        vector<int> letters1(26,0), letters2(26,0);
        for (int i = 0; i < s1.length(); i++){
            letters1[s1[i] - 'a']++;
            letters2[s2[i] - 'a']++;
        }
        for (size_t i = 0; i < 26; i++){
            if (letters1[i] != letters2[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int length = s.length();
    int sum = 0;
    for(int substringLength = 1; substringLength < length; substringLength++){
        vector<string> subStrings;
        for (int n=0; n < length - substringLength + 1 ; n++){
            subStrings.push_back(s.substr(n, substringLength));
        }
        for (auto it = subStrings.begin();it!=subStrings.end()-1;++it){
            for (auto itNext = it+1;itNext!=subStrings.end();++itNext){
                if (isAnagram(*it,*itNext)){
                    sum++;
                }
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
