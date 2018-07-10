#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
  // right
  int r_r_obstacle = -1;
  int c_r_obstacle = -1;
  // bottom right
  int r_br_obstacle = -1;
  int c_br_obstacle = -1;
  // bottom
  int r_b_obstacle = -1;
  int c_b_obstacle = -1;
  // bottom left
  int r_bl_obstacle = -1;
  int c_bl_obstacle = -1;
  // left
  int r_l_obstacle = -1;
  int c_l_obstacle = -1;
  // top left
  int r_tl_obstacle = -1;
  int c_tl_obstacle = -1;
  // top
  int r_t_obstacle = -1;
  int c_t_obstacle = -1;
  // top right
  int r_tr_obstacle = -1;
  int c_tr_obstacle = -1;

  int reachable_squares = 0;
  for(int i = 0; i < k; i++){
    int obstacle_row = obstacles[i][0];
    int obstacle_col = obstacles[i][1];
    //Right
    if((obstacle_col < c_r_obstacle || obstacle_row == -1) && obstacle_col > c_q && obstacle_row == r_q) {
        r_r_obstacle = obstacle_row;
        c_r_obstacle = obstacle_col;
    }
    //Bottom Right
    if(r_q - obstacle_row == obstacle_col - c_q && obstacle_col > c_q && obstacle_row < r_q
       && ((obstacle_row > r_br_obstacle && obstacle_col < c_br_obstacle) || r_br_obstacle == -1)) {
        r_br_obstacle = obstacle_row;
        c_br_obstacle = obstacle_col;
    }

    //Bottom
    if((obstacle_row > r_b_obstacle || r_b_obstacle == -1) && obstacle_row < r_q && obstacle_col == c_q)
    {
        r_b_obstacle = obstacle_row;
        c_b_obstacle = obstacle_col;
    }

    //Bottom Left
    if(r_q - obstacle_row == c_q - obstacle_col && obstacle_col < c_q && obstacle_row < r_q
       && ((obstacle_row > r_bl_obstacle && obstacle_col > c_bl_obstacle) || r_bl_obstacle == -1))
    {
        r_bl_obstacle = obstacle_row;
        c_bl_obstacle = obstacle_col;
    }

    //Left
    if((obstacle_col > c_l_obstacle || r_l_obstacle == -1) && obstacle_col < c_q && obstacle_row == r_q)
    {
        r_l_obstacle = obstacle_row;
        c_l_obstacle = obstacle_col;
    }

    //Top Left
    if(c_q - obstacle_col == obstacle_row - r_q && obstacle_col < c_q && obstacle_row > r_q
       && ((obstacle_row < r_tl_obstacle && obstacle_col > c_tl_obstacle) || r_tl_obstacle == -1))
    {
        r_tl_obstacle = obstacle_row;
        c_tl_obstacle = obstacle_col;
    }

    //Top
    if((obstacle_row < r_t_obstacle || r_t_obstacle == -1) && obstacle_row > r_q && obstacle_col == c_q)
    {
        r_t_obstacle = obstacle_row;
        c_t_obstacle = obstacle_col;
    }

    //Top Right
    if(obstacle_row - r_q == obstacle_col - c_q && obstacle_col > c_q
       && obstacle_row > r_q && ((obstacle_row < r_tr_obstacle && obstacle_col < c_tr_obstacle) || r_tr_obstacle == -1))
    {
        r_tr_obstacle = obstacle_row;
        c_tr_obstacle = obstacle_col;

    }
  }

  reachable_squares += (c_r_obstacle != -1) ? (c_r_obstacle - c_q -1) : n - c_q;
  reachable_squares += (r_b_obstacle != -1) ? (r_q - r_b_obstacle - 1) : r_q - 1;
  reachable_squares += (c_l_obstacle != -1) ? (c_q - c_l_obstacle -1) : c_q - 1;
  reachable_squares += (r_t_obstacle != -1) ? (r_t_obstacle - r_q - 1) : n - r_q;

  //BR BL TL TR
  reachable_squares += (c_br_obstacle != -1) ? (c_br_obstacle - c_q -1) : min(n - c_q, r_q - 1);
  reachable_squares += (r_bl_obstacle != -1) ? (c_q - c_bl_obstacle - 1) : min(c_q - 1, r_q - 1);
  reachable_squares += (c_tl_obstacle != -1) ? (c_q - c_tl_obstacle -1) : min(c_q - 1, n - r_q);
  reachable_squares += (r_tr_obstacle != -1) ? (c_tr_obstacle - c_q - 1) : min(n - c_q, n - r_q);

  return reachable_squares;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


/*
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int rQueen = in.nextInt();
        int cQueen = in.nextInt();

        //Row Column coordinates of the closes object in each direction
        int rRObstacle = -1;
        int cRObstacle = -1;
        int rBRObstacle = -1;
        int cBRObstacle = -1;
        int rBObstacle = -1;
        int cBObstacle = -1;
        int rBLObstacle = -1;
        int cBLObstacle = -1;
        int rLObstacle = -1;
        int cLObstacle = -1;
        int rTLObstacle = -1;
        int cTLObstacle = -1;
        int rTObstacle = -1;
        int cTObstacle = -1;
        int rTRObstacle = -1;
        int cTRObstacle = -1;

        //Total squares attacked by the queen
        int reachableSquares = 0;

        //Finds the closest object in each direction
        for(int a0 = 0; a0 < k; a0++){
            int rObstacle = in.nextInt();
            int cObstacle = in.nextInt();

            //Right
            if((cObstacle < cRObstacle || rRObstacle == -1) && cObstacle > cQueen && rObstacle == rQueen)
            {
                rRObstacle = rObstacle;
                cRObstacle = cObstacle;
            }

            //Bottom Right
            if(rQueen - rObstacle == cObstacle - cQueen && cObstacle > cQueen && rObstacle < rQueen
               && ((rObstacle > rBRObstacle && cObstacle < cBRObstacle) || rBRObstacle == -1))
            {
                rBRObstacle = rObstacle;
                cBRObstacle = cObstacle;
            }

            //Bottom
            if((rObstacle > rBObstacle || rBObstacle == -1) && rObstacle < rQueen && cObstacle == cQueen)
            {
                rBObstacle = rObstacle;
                cBObstacle = cObstacle;
            }

            //Bottom Left
            if(rQueen - rObstacle == cQueen - cObstacle && cObstacle < cQueen && rObstacle < rQueen
               && ((rObstacle > rBLObstacle && cObstacle > cBLObstacle) || rBLObstacle == -1))
            {
                rBLObstacle = rObstacle;
                cBLObstacle = cObstacle;
            }

            //Left
            if((cObstacle > cLObstacle || rLObstacle == -1) && cObstacle < cQueen && rObstacle == rQueen)
            {
                rLObstacle = rObstacle;
                cLObstacle = cObstacle;
            }

            //Top Left
            if(cQueen - cObstacle == rObstacle - rQueen && cObstacle < cQueen && rObstacle > rQueen
               && ((rObstacle < rTLObstacle && cObstacle > cTLObstacle) || rTLObstacle == -1))
            {
                rTLObstacle = rObstacle;
                cTLObstacle = cObstacle;
            }

            //Top
            if((rObstacle < rTObstacle || rTObstacle == -1) && rObstacle > rQueen && cObstacle == cQueen)
            {
                rTObstacle = rObstacle;
                cTObstacle = cObstacle;
            }

            //Top Right
            if(rObstacle - rQueen == cObstacle - cQueen && cObstacle > cQueen
               && rObstacle > rQueen && ((rObstacle < rTRObstacle && cObstacle < cTRObstacle) || rTRObstacle == -1))
            {
                rTRObstacle = rObstacle;
                cTRObstacle = cObstacle;
            }

        }

        //Calculates the distance to the closest obstacle in each direction and adds it to reachableSquares
        //R B L T
        reachableSquares += (cRObstacle != -1) ? (cRObstacle - cQueen -1) : n - cQueen;
        reachableSquares += (rBObstacle != -1) ? (rQueen - rBObstacle - 1) : rQueen - 1;
        reachableSquares += (cLObstacle != -1) ? (cQueen - cLObstacle -1) : cQueen - 1;
        reachableSquares += (rTObstacle != -1) ? (rTObstacle - rQueen - 1) : n - rQueen;

        //BR BL TL TR
        reachableSquares += (cBRObstacle != -1) ? (cBRObstacle - cQueen -1) : Math.min(n - cQueen, rQueen - 1);
        reachableSquares += (rBLObstacle != -1) ? (cQueen - cBLObstacle - 1) : Math.min(cQueen - 1, rQueen - 1);
        reachableSquares += (cTLObstacle != -1) ? (cQueen - cTLObstacle -1) : Math.min(cQueen - 1, n - rQueen);
        reachableSquares += (rTRObstacle != -1) ? (cTRObstacle - cQueen - 1) : Math.min(n - cQueen, n - rQueen);
        System.out.println(reachableSquares);
    }
} */
