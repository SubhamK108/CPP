#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>


void showboard(vector <char> v)
{
    system("clear");
    cout << v[0] << "  |  " << v[1] << "  |  " << v[2] << endl;
    cout << "___|_____|___" << endl;
    cout << "   |     |  " << endl;
    cout << v[3] << "  |  " << v[4] << "  |  " << v[5] << endl;
    cout << "___|_____|___" << endl;
    cout << "   |     |  " << endl;
    cout << v[6] << "  |  " << v[7] << "  |  " << v[8] << endl;
}

bool checkline(vector <char> v, char ch, int a, int b, int c)
{
    if (v[a] == ch && v[b] == ch && v[c] == ch) { return (true); }
    return (false);
}

bool checkall(vector <char> v, char ch)
{
    if (checkline(v, ch, 0, 1, 2)) { return (true); }
    if (checkline(v, ch, 3, 4, 5)) { return (true); }
    if (checkline(v, ch, 6, 7, 8)) { return (true); }
    if (checkline(v, ch, 0, 3, 6)) { return (true); }
    if (checkline(v, ch, 1, 4, 7)) { return (true); }
    if (checkline(v, ch, 2, 5, 8)) { return (true); }
    if (checkline(v, ch, 0, 4, 8)) { return (true); }
    if (checkline(v, ch, 2, 4, 6)) { return (true); }
    return (false);
}

void checkdraw(vector <char> v)
{
    int m = 0;
    for (int i = 0; i < 9; i++)
    {
        if (v[i] == 'X' || v[i] == 'O') { m += 1; }
        if (m == 9)
        {
            cout << "           .....DRAW....." << endl;
            exit(0);
        }
    }
}


int main()
{
    system("clear");
    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector <char> board;
    board.assign(arr, arr + 9);
    showboard(board);
    int p1, p2;
    while (true)
    {
        cout << "               Turn of 'X': ";
        cin >> p1;
        p1--;
        if (board[p1] != 'X' && board[p1] != 'O')
        {
            board[p1] = 'X';
            showboard(board);
            if (checkall(board, 'X'))
            {
                cout << "               .....X WINS....." << endl;
                exit(0);
            }
            checkdraw(board);
            while (true)
            {
                cout << "               Turn of 'O': ";
                cin >> p2;
                p2--;
                if (board[p2] != 'X' && board[p2] != 'O')
                {
                    board[p2] = 'O';
                    showboard(board);
                    if (checkall(board, 'O'))
                    {
                        cout << "               .....O WINS....." << endl;
                        exit(0);
                    }
                    checkdraw(board);
                }
                else
                {
                    cout << "                This spot is already taken !" << endl;
                    continue;
                }
                break;
            }
        }
        else
        {
            cout << "                This spot is already taken !" << endl;
            continue;
        }
    }
}