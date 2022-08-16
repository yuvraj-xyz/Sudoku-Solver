#include <bits/stdc++.h>
using namespace std;

// Sudoku Solver
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for(int i=0; i<9; i++)
    {
        if(board[row][i]==c)
        {
            return false;
        }
        if(board[i][col]==c)
        {
            return false;
        }
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1'; c<='9'; c++)
                {
                    if(isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if(solve(board) == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board
    {
        {".",".",".","9","5","1",".","8","."},
        {"9","5",".",".",".",".",".",".","1"},
        {"6","1","7",".",".","3",".","5","."},
        {"8",".",".",".",".",".",".",".","9"},
        {"3","9",".",".","1","7","2","4","6"},
        {"8","4","6",".","9",".","7","1","5"},
        {"2",".",".","5",".",".",".",".","."},
        {"7",".",".","6",".","4","5",".","8"},
        {"5","6","9",".","3",".",".",".","."}
    };
    solve(board);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
