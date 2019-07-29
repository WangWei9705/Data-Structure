/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-29 11:16:17
 * Filename      : DFS_6.cpp
 * Description   : 岛屿数量
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void DFS(vector<vector<char> >& grid, int x, int y, int row, int col) {
    grid[x][y] = '*';

    for(int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == '1') {
            DFS(grid, nx, ny, row, col);
        }
    }
    
}


int solve(vector<vector<char> >& grid) {
    if(grid.empty()) {
        return 0;
    }
    int row = grid.size();
    int col = grid[0].size();
    
    int count = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            count++;
            DFS(grid, i, j, row, col);
        }
    }

    return count;
}

int main()
{
    int n, m;
    while(cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m, 'X'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << solve(grid) << endl;

        
    }
    return 0;
}

