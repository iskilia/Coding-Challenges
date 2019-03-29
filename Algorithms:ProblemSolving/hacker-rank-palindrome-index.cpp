#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    string tmp = s;
    bool check = true;
    reverse(tmp.begin(),tmp.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] != tmp[i]){
            check = false;
            break;
        }
    }
    return check;
}
string conCat(string str,int index){
    string tmp;
    for(int i = 0; i < str.size();i++){
        if(i != index)tmp.push_back(str[i]);
    }
    return tmp;
}

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    if(isPalindrome(s)){
        return -1;
    } else {
        int index = -1,len = s.size();
        for(int i = 0; i < len/2; i++){
            if(s[i] != s[len-i-1]){
                if(isPalindrome(conCat(s,i)))index = i;
                if(isPalindrome(conCat(s,len-i-1)))index = len-i-1;
                break;
            }
        }
        return index;
    }
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
