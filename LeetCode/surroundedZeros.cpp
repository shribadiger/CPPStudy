/* Leet code problem*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<string>> &board, int i, int j)
{
    if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == "O")
    {
        board[i][j] = "A";
        dfs(board, i, j + 1); // left node
        dfs(board, i - 1, j); // right node
        dfs(board, i, j - 1); // top node
        dfs(board, i + 1, j); // botton node
    }
}
void solve(vector<vector<string>> &board)
{
    int rows = board.size();    // number of rows
    int cols = board[0].size(); // number of cols

    // if the only 2 rows and cols means all values are border
    if (rows <= 2 || cols <= 2)
        return;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == "O" && (i == 0 || i == rows - 1 || j == 0 || j == cols - 1))
            {
                dfs(board, i, j);
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == "O")
                board[i][j] = "X";
            else if (board[i][j] == "A")
                board[i][j] = 'O';
        }
    }
}
int main()
{

    vector<vector<string>> board = {{"X", "X", "X", "X"},
                                    {"X", "O", "O", "X"},
                                    {"X", "X", "O", "X"},
                                    {"X", "O", "X", "X"}};
    solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (auto val : board[i])
        {
            cout << "\t" << val;
        }
        cout << "\n";
    }
}