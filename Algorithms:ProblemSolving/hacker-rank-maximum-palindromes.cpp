#include <bits/stdc++.h>
#define FOR(x,to) for(x=0;x<(to);x++)
using namespace std;

typedef signed long long ll;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int NUM_ = 200003;
static ll fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
int frequencies[26][101010];
ll mod = 1000000007;

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

void initialize(string s) {
    // This function is called once before all queries.
    int n = s.size();
    int i, x;
    FOR(i,26) {
        FOR(x,n) {
            frequencies[i][x+1]=frequencies[i][x]+(s[x] == 'a'+i);
        }
    }
    inv[1]=fact[0]=factr[0]=1;
    for (int i=2;i<=NUM_;++i){
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (int i=1;i<=NUM_;++i){
        fact[i]=fact[i-1] * i % mod;
        factr[i]=factr[i-1] * inv[i] % mod;
    }
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    int left = l - 1;
    int right = r;
    int num[26] = {}, odd = 0, sum = 0;
    int i;
    FOR(i,26) {
        num[i]=(frequencies[i][right]-frequencies[i][left])/2;
        sum+=num[i];
        if((frequencies[i][right]-frequencies[i][left])&1) odd++;
    }
    ll ans = odd?odd:1;
    (ans*=fact[sum])%=mod;
    FOR(i,26) {
        ans = ans*factr[num[i]]%mod;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
