/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-22 18:32:28
 * Filename      : dp_6.cpp
 * Description   : 动态规划练习6——路径总数(无障碍物)
 * *******************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int step(int m, int n)  {
    if(n == 0 || m == 0) {
        return 0;
    }

    // 第一行和第一列的方法数都为1
    vector<vector<int>> step(m, vector<int>(n,1));
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            step[i][j] = step[i-1][j] + step[i][j-1];
        }
    }

    return step[m-1][n-1];
}
int main()
{
    int n,m;
    while(cin >> n >> m) {
        vector<vector<string>> v(m, vector<string>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string str = " ";
                cin >> str[i];
                v.push_back(str[i]);
            }
        }
    }
    return 0;
}

