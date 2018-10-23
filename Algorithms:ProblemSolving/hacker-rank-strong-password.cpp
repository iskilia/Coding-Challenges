#include <bits/stdc++.h>
using namespace std;
// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    bool hasNumber = false, hasLower = false, hasUpper = false, hasSpecial = false;
    for(int i = 0; i < password.length(); i++){
        if(numbers.find(password[i]) != string::npos){
            hasNumber = true;
        } else if(lower_case.find(password[i]) != string::npos){
            hasLower = true;
        } else if(upper_case.find(password[i]) != string::npos){
            hasUpper = true;
        } else if(special_characters.find(password[i]) != string::npos){
            hasSpecial = true;
        }
    }

    int remaining = 0;
    if(!hasNumber) remaining++;
    if(!hasLower) remaining++;
    if(!hasUpper) remaining++;
    if(!hasSpecial) remaining++;
    if(password.length() + remaining < 6) remaining += 6 - (password.length()+remaining);
    return remaining;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
