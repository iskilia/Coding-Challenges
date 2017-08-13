/* Lena Sort - Hackerrank */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define UPPERLIMIT 100001
//this file is in c++
using namespace std;

void optimal_array(int n, int s){
    int median, new_len1, new_len2, new_in1, new_in2;
    if (n==1){
        cout<<s<<" ";
    }
    else if (n==2){
        cout<<s<<" "<<s+1<<" ";
    }
    else if (n>2){
        if (n%2==1){
            median = s+(n-n%2)/2;
            cout<< median <<" ";
            new_len1 = (n-n%2)/2;
            new_len2 = (n-n%2)/2;
            new_in1 = s;
            new_in2 = median + 1;
            optimal_array(new_len1, new_in1);
            optimal_array(new_len2, new_in2);
        }
        else {
            median = s+n/2;
            cout<< median <<" ";
            new_len1 = (n/2);
            new_len2 = (n/2)-1;
            new_in1 = s;
            new_in2 = median + 1;
            optimal_array(new_len1, new_in1);
            optimal_array(new_len2, new_in2);
        }
    }
}

void generate_array(int n, int c, int s, vector<int> &BestCase){
    if (BestCase[n]==c){
        optimal_array(n,s);
    }
    else {
        c-=(n-1);
        int a=n-1;
        int b=0;
        while (BestCase[a]+BestCase[b]>c){
            a--;
            b++;
        }
        int sa=s;
        int sb=s+a+1;
        //cout<<"Dividing "<<n<<" into "<<a<<" and "<<b<<endl;
        cout<<s+a<<" ";
        generate_array(a,c-BestCase[b],sa,BestCase);
        optimal_array(b,sb);
    }
}

int main() {
    int q,i,j,lower_bound,upper_bound;
    cin>>q;
    vector<int> BestCase(UPPERLIMIT);
    BestCase[0]=0;
    BestCase[1]=0;
    for (i=2; i<UPPERLIMIT; i++){
        lower_bound =((i-1)-(i-1)%2)/2;
        upper_bound =((i-1)+(i-1)%2)/2;
        BestCase[i]=i-1+BestCase[lower_bound]+BestCase[upper_bound];
    }
    for (j=0; j<q; j++){
        long long len;
        int c;
        cin>>len>>c;
        long long worst=len*(len-1)/2;
        int best=BestCase[len];
        if (c>worst || c<best){
            //cout<<c<<" "<<worst<<" "<<best<<endl;
            cout<<-1<<endl;
        }
        else {
            generate_array(len, c, 1, BestCase);
            cout<<endl;
        }
    }
    return 0;
}
