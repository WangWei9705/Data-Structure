/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-29 16:08:50
 * Filename      : DFS_7.cpp
 * Description   : 岛屿最大面积
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}
int DFS(vector<vector<int> >& grid, int x, int y, int row, int col) {
    grid[x][y] = -1;
    int rear = 1;


    for(int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
           rear +=  DFS(grid, nx, ny, row, col);
        }
    }

    return rear;

}


int maxrear(vector<vector<int> >& grid) {
    if(grid.empty()) {
        return 0;
    }
    int maxrear = 0;
    int row = grid.size();
    int col = grid[0].size();
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == 1) {
                maxrear = max(maxrear, DFS(grid, i, j, row, col));
            }
        }

    }
        return maxrear;
}
int main()
{
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << maxrear(grid) << endl;
    }
    return 0;
}

