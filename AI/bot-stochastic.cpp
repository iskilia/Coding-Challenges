#include<iostream>
#include<vector>
using namespace std;

void nextMove(int posr, int posc, vector <string> board) {
    //add logic here
    int dirty_x, dirty_y;
    for (int k = 0; k < board.size(); k++){
            if (board[k].find("d") != std::string::npos){
                dirty_x = k;
                dirty_y = board[k].find("d");
                if(posr == dirty_x && dirty_y == posc){
                    cout << "CLEAN" << endl;
                    return;
                }
                break;
            }
    }
    if (dirty_y < posc)
        cout << "LEFT" << endl;
    else if (dirty_y > posc)
        cout << "RIGHT" << endl;
    else if (dirty_x != posr)
        {
            string out = (dirty_x < posr) ? "UP" : "DOWN";
            cout << out << endl;
        }
    return;
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}
