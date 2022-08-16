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
        {'.','.','.','.','6','8','2','4','5'},
        {'6','.','.','5','.','4','7','.','.'},
        {'2','4','5','.','.','7','3','6','8'},
        {'5','.','.','2','.','1','6','8','7'},
        {'.','7','.','.','5','.','.','.','3'},
        {'.','.','6','.','8','.','4','.','.'},
        {'7','.','.','.','3','2','.','.','.'},
        {'3','9','.','8','.','.','.','7','.'},
        {'4','6','1','9','7','.','8','.','2'}
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
