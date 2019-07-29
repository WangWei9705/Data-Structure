/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-29 10:17:39
 * Filename      : DFS_4.cpp
 * Description   : 求岛屿周长
 * 0 1 0 0           左边周长为16，思路：只要当前岛屿有相邻岛屿就在之前的结果上-2
 * 1 1 1 0
 * 0 1 0 0
 * 1 1 0 0
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
int islandPerimeter(vector<vector<int> >& grid) {
        if(grid.empty()) {
            return 0;
        }
        
        int row = grid.size();
        int col = grid[0].size();
        int ret = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    ret += 4;
                    
                    if(i > 0 && grid[i-1][j] == 1) {
                        ret -= 2;
                    }
                
                    if(j > 0 && grid[i][j-1] == 1) {
                        ret -= 2;
                    }
                }
                
                
            }
        }
        return ret;
        
    }
int DFS(vector<vector<int> >& grid) {
    if(grid.empty()) {
        return 0;
    }

    int n = grid.size();
    int m = grid[0].size();
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                ret += 4;
                if(i > 0 && grid[i-1][j] == 1) {
                    ret -= 2;
                }

                if(j > 0 && grid[i][j-1] == 1) {
                    ret -= 2;
                }
            }
        }
    }

    return ret;
}

int main()
{
    int n,m;
    while(cin >> n >> m) {
        vector<vector<int> > grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << DFS(grid) << endl;

    }
    return 0;
}

