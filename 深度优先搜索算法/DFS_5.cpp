/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-29 10:49:14
 * Filename      : DFS_5.cpp
 * Description   : 填充被围绕区域
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void DFS(vector<vector<char> >& board, int x, int y, int row, int col) {
    if(board.empty()) {
        return;
    }

    board[x][y] = '*';   // 标记当前位置
    for(int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col && board[nx][ny] == 'O') {
            DFS(board, nx, ny, row, col);
        }
    }
}

int main()
{
    int n, m;
    while(cin >> n >> m) {
        vector<vector<char> > board(n, vector<char>(m, 'O'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O') {
                DFS(board, i, 0, row, col);
            }

            if(board[i][col-1] == 'O') {
                DFS(board, i, col-1, row, col);
            }
        }

        for(int j = 0; j < col; j++) {
            if(board[0][j] == 'O') {
                DFS(board, 0, j, row, col);
            }

            if(board[row-1][j] == 'O') {
                DFS(board, row-1, j, row, col);
            }
        }


        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }


        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        
    }
    return 0;
}

