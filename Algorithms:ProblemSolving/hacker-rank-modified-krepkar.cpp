#include <bits/stdc++.h>

using namespace std;

long long digitCount(long long x){
    long long cnt = 0;
    while(x){
        cnt++;
        x/=10;

    }
    return cnt;
}

long long splitNumber(long long x){
    long long tmp = 1;
    while(x){
        tmp*=10;
        x--;
    }
    return tmp;
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(long long p, long long q) {
  bool flag = true;
  for(long long i = p; i <= q; i++){
    long long a,b,digit,sq;
    sq = i*i;
    digit = digitCount(sq);
    digit -= (digit/2);
    a = sq / splitNumber(digit);
    b = sq % splitNumber(digit);
    if((a+b) == i){
        cout << i << " ";
        flag = false;
    }
  }
   if(flag) cout << "INVALID RANGE";
   cout << endl;
}

int main()
{
    long long p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
