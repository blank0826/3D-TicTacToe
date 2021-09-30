#include <bits/stdc++.h>
using namespace std;
#define t int
#define sz 3

class MagicCube{
public:
    void getMagicCube(t Cube[][sz][sz]){
        if (sz % 2 == 1){
            t lay, row, col;
            lay = 0;
            row = sz / 2;
            col = sz / 2;
            for (t i = 0; i < sz; i++)
                for (t j = 0; j < sz; j++)
                    for (t k = 0; k < sz; k++)
                        Cube[i][j][k] = 0;
            for (t i = 0; i < (t)pow(sz, 3); i++){
                Cube[lay][row][col] = i + 1;
                lay--;
                lay = modify(lay);
                col--;
                col = modify(col);
                if (Cube[lay][row][col] != 0){
                    row--;
                    row = modify(row);
                    col++;
                    col = modify(col);
                    if (Cube[lay][row][col] != 0){
                        row++;
                        row = modify(row);
                        lay += 2;
                        lay = modify(lay);
                    }
                }
            }
        }
        cout<<"Magic Cube of order "<<sz<<": \n\n";
        for (t i = 0; i < sz; i++){
            cout<<"Layer "<<i+1<<": \n";
            for (t j = 0; j < sz; j++){
                for (t k = 0; k < sz; k++)
                    cout << Cube[i][j][k] << " ";
                cout << "\n";
            }
            cout << "\n";
        }
    }
    t modify(t cur){
        while (cur < 0)
            cur += sz;
        while (cur > sz-1)
            cur -= sz;
        return cur;
    }
};

struct Point{ //Structure to represent the coordinates in cube.;
    t i, j, k;
};

void displayBoard(t arr[][sz][sz]){
    cout << "\nCurrent Status: \n";
    t i = 0;
    for (t i = 0; i < 3; i++){
        for (t j = 0; j < 3; j++){
            for (t k = 0; k < 3; k++){
                if (arr[i][j][k] == 99)
                    cout << "X";
                else if (arr[i][j][k] == 100)
                    cout << "O";
                else
                    cout << arr[i][j][k];
                if (k < 2)
                    cout << " | ";
            }
            cout << "\n";
            if (j < 2)
                cout << "---------" << "\n";
            else
                cout << "\n";
        }
    }
}

bool checkCollinear(Point A, Point B, Point C){ //Utility to check if 3 Points are collinear
    Point AB, AC;
    AB.i = B.i - A.i, AB.j = B.j - A.j, AB.k = B.k - A.k;
    AC.i = C.i - A.i, AC.j = C.j - A.j, AC.k = C.k - A.k;
    double val = pow((AB.i * AC.i + AB.j * AC.j + AB.k * AC.k), 2) / ((1.0) * (AB.i * AB.i + AB.j * AB.j + AB.k * AB.k) * (AC.i * AC.i + AC.j * AC.j + AC.k * AC.k));
    if (val == 1)
        return true;
    else
        return false;
}

t make_2(bool mm[], t C[][sz][sz]){
    for(t i=0;i<3;i++)
        for(t j=0;j<3;j++)
            for(t k=0;k<3;k++){
                if(mm[C[i][j][k]] == 0 && C[i][j][k]!=99 && C[i][j][k]!=100)
                    return C[i][j][k];
                else{
                    while (true){
                        t move = rand() % 27 + 1;
                        if (mm[move] == 0 && move != 99 && move != 100)
                            return move;
                    }
                }
            }
}
//Utility to find whether a win is possible
t possWin(vector<t> &Progress, bool nonRows[][28][28], Point M[], bool mm[]){
    t n = Progress.size();
    if (n < 2)
        return 0;
    for (t i = 0; i < n; i++){
        for (t j = i + 1; j < n; j++){
            t latestmove = 42 - Progress[i] - Progress[j];
            if (latestmove <= 27 && latestmove != Progress[i] && latestmove != Progress[j]){
                if (!mm[latestmove]){
                    t n1 = min(Progress[i], min(Progress[j], latestmove)), n3 = max(Progress[i], max(Progress[j], latestmove));
                    t n2 = 42 - n1 - n3;
                    if (!nonRows[n1][n2][n3]){
                        Point P = M[n1], Q = M[n2], R = M[n3];
                        if (checkCollinear(P, Q, R) == 1)
                            return latestmove;
                    }
                }
            }
        }
    }
    return 0;
}

bool PointEarned(vector<t> &Progress, bool captured[][28][28], Point M[], bool nonRows[][28][28]){
    t n = Progress.size();
    if (n < 3)
        return 0;
    for (t i = 0; i < n; i++){
        for (t j = i + 1; j < n; j++){
            for (t k = j + 1; k < n; k++){
                if (Progress[i] + Progress[j] + Progress[k] == 42){
                    t n1 = min(Progress[i], min(Progress[j], Progress[k])), n3 = max(Progress[i], max(Progress[j], Progress[k]));
                    t n2 = 42 - n1 - n3;
                    if (!nonRows[n1][n2][n3]){
                        Point A = M[n1], B = M[n2], C = M[n3];
                        if (checkCollinear(A, B, C) == 1 && !captured[n1][n2][n3]){
                            captured[n1][n2][n3] = 1;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void makeMove(vector<t> &Human, vector<t> &Comp, t C[][sz][sz], bool nonRows[][28][28], Point M[]){
    t cHuman = 0, cComp = 0;
    bool mm[28] = {};
    bool captured[28][28][28] = {};
    t move;
    for (t i = 1; i <= 27; i++){
        if (i % 2 == 1){ //Human's moves
            cout << "Enter the move you want to play: ";
            cin >> move;
            while (mm[move]){
                cout << "This space has already been filled. Select another: ";
                cin >> move;
            }
            Human.push_back(move);
            for (t i = 0; i < 3; i++)
                for (t j = 0; j < 3; j++)
                    for (t k = 0; k < 3; k++)
                        if (C[i][j][k] == move)
                            C[i][j][k] = 99;
            mm[move] = 1;
            if (PointEarned(Human, captured, M, nonRows)){
                cHuman++;
                if (cHuman == 10){
                    cout << "You win! :D";
                    return;
                }
            }
        }
        else{
            if (i / 2 < 2){  // first two moves of computer
                t move = make_2(mm,C);
                Comp.push_back(move);
                for (t i = 0; i < 3; i++)
                    for (t j = 0; j < 3; j++)
                        for (t k = 0; k < 3; k++)
                            if (C[i][j][k] == move)
                                C[i][j][k] = 100;
                mm[move] = 1;
            }
            else{
                t winMov = possWin(Comp, nonRows, M, mm); //Computer's possible winning move
                if (winMov > 0 && !mm[winMov]){
                    Comp.push_back(winMov);
                    for (t i = 0; i < 3; i++)
                        for (t j = 0; j < 3; j++)
                            for (t k = 0; k < 3; k++)
                                if (C[i][j][k] == winMov)
                                    C[i][j][k] = 100;
                    mm[winMov] = 1;
                    PointEarned(Comp, captured, M, nonRows);
                    cComp++;
                    if (cComp == 10){
                        cout << "Computer Wins! :(";
                        return;
                    }
                }
                else{
                    winMov = possWin(Human, nonRows, M, mm); //Block Human's possible winning move
                    if (winMov && !mm[winMov]){
                        Comp.push_back(winMov);
                        for (t i = 0; i < 3; i++)
                            for (t j = 0; j < 3; j++)
                                for (t k = 0; k < 3; k++)
                                    if (C[i][j][k] == winMov)
                                        C[i][j][k] = 100;
                        mm[winMov] = 1;
                    }
                    else{
                        move = make_2(mm, C); // if nothing is possible
                        Comp.push_back(move);
                        for (t i = 0; i < 3; i++)
                            for (t j = 0; j < 3; j++)
                                for (t k = 0; k < 3; k++)
                                    if (C[i][j][k] == move)
                                        C[i][j][k] = 100;
                        mm[move] = 1;
                    }
                }
            }
            displayBoard(C);
        }
    }
    displayBoard(C);
    cout << "It's a tie! \n";
}

t main(){
    t opt;
    t Cube[sz][sz][sz];
    MagicCube C;
    C.getMagicCube(Cube);
    Point X[28];
    for (t i = 0; i < 3; i++){
        for (t j = 0; j < 3; j++){
            for (t k = 0; k < 3; k++){
                Point A; // The 3D space gets initialized
                A.i = i, A.j = j, A.k = k;
                X[Cube[i][j][k]] = A;
            }
        }
    }
    bool counter[28][28][28] = {};
    bool nonRow[28][28][28] = {};
    for (t a = 1; a <= 27; a++){
        for (t b = a + 1; b <= 27; b++){
            t c = 42 - a - b;
            if (c > 0 && c <= 27 && c != a && c != b){
                t n1 = min(a, min(b, c)), n3 = max(a, max(b, c));
                t n2 = 42 - n1 - n3;
                if (!counter[n1][n2][n3]){
                    counter[n1][n2][n3] = 1;
                    Point A = X[n1], B = X[n2], C = X[n3];
                    if (!checkCollinear(A, B, C))
                        nonRow[n1][n2][n3] = 1;
                }
            }
            else
                break;
        }
    }
    cout<<"3D Tic Tac Toe \nX->Human\nO->Computer\n\n";
    vector<t> Human, Comp;
    makeMove(Human, Comp, Cube, nonRow, X);
    return 0;
}

