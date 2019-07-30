/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-30 10:52:12
 * Filename      : dp_8.cpp
 * Description   : 最小路径和
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;


int dp(vector<vector<int> >& grid, int n, int m) {

    // 吐过数组为空或者只有一行则返回0
    if(grid.empty() || grid[0].size()) {
        return 0;
    }

    vector<vector<int> > step(n, vector<int>(m ,0));
    // 初始化
    step[0][0] = grid[0][0];
    for(int i = 1; i < n; i++) {
        step[i][0] = grid[i][0] + step[i-1][0];
    }
    for(int j = 1; j < m; j++) {
        step[0][j] = grid[0][j] + step[0][j-1];
    }

    for(int i = 1; i < n; i++) {
        for(int j  = 1; j < m; j++) {
            step[i][j] = grid[i][j] + min(step[i-1][j], step[i][j-1]);
        }
    }

    return step[n-1][n-1];
}
int main()
{
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int> >grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << dp(grid) << endl;
    }
    return 0;
}

