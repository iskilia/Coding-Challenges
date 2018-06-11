#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num_queries;
    cin >> num_queries;
    set<int> s;
    for(int i = 0;  i < num_queries; i++){
    	int c,val;
	cin >> c;
	switch(c){
	    case 1:
		cin >> val;
		s.insert(val);
		break;
	    case 2:
		cin >> val;
		s.erase(s.find(val));
		break;
	    case 3:
		cout << *s.begin() << endl;
		break;
	}
    }
    return 0;
}

