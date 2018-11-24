#include <bits/stdc++.h>

using namespace std;

bool check(string s,int ind ,long long int prev){
    if(ind == s.size() -1 && prev - (s[ind] -'0') == -1){
        return true;
    }
    else if(ind == s.size() ) return true;
    long long int k=0;
    for(int i =ind; i < s.size(); i++){
        k = k *10 + (s[i]-'0');
        if(prev - k == -1){
             if( i + 1 == s.size()){
              return true;
            
            }
            return check(s,i+1, k);
        }  
        else if(k - prev > 1) {
            return false;
        }
        
    }
    return false;
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    if(s[0] == '0' || s.size() <=1){
        cout << "NO"<<endl; 
        return;
    }
    long long int j = 0;
    bool isValid = false;
    for(int k =0; k < s.size()-1; k++){
        j = j*10 +s[k]-'0';
        isValid = check(s,k+1,j);
        if(isValid == true){ 
            cout << "YES " << j <<endl;
            break;
        }
    }
    if(isValid == false) cout <<"NO" <<endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
