#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    map <string, string> HRMLmap;
    string inputstr,tag_preamble="";
    for (int i = 0; i < N; i++){
        getline(cin, inputstr);
        stringstream ss(inputstr);
        string word, attribute, value;
        size_t pos;
        while(getline(ss,word,' ')){
            if (word[0]=='<') {
                string tag;
                if (word[1]=='/') { // it's tag closing
                    tag=word.substr(2);
                    tag=tag.substr(0,tag.length()-1); // rid of ">"
                    pos=tag_preamble.find("."+tag);
                    if (pos==string::npos) tag_preamble="";
                    else tag_preamble=tag_preamble.substr(0,pos);
                }
                else { // it's tag opening
                    tag=word.substr(1);
                    if (tag.find(">")!=string::npos)
                    tag=tag.substr(0,tag.length()-1); // rid of ">"
                    if (tag_preamble=="") tag_preamble=tag;
                    else tag_preamble=tag_preamble+"."+tag;
                }
            }else if (word[0]=='"') {
                pos=word.find_last_of('"');
                value=word.substr(1,pos-1);
                HRMLmap[attribute]=value;
            }
            // attribute name detected
            else if (word[0]!='=') {
                attribute=tag_preamble + "~" + word;
            }
        }
    }
    for (int i=0;i < Q; i++) {
        getline(cin,inputstr);
        if (HRMLmap.find(inputstr)==HRMLmap.end())
            cout << "Not Found!" << endl;
        else
            cout << HRMLmap[inputstr] << endl;
    }
    return 0;
}
