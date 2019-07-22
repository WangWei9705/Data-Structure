/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-22 19:51:24
 * Filename      : dp_7.cpp
 * Description   : 动态规划练习7——路径总和（有障碍物）
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

int step(vector<vector<int>>& v) {
    if(v.empty() || v[0].empty()) {
        return 0;
    }

    int m = v.size();
    int n = v[0].size();
    vector<vector<int>> step(m, vector<int>(n, 0));

    // 第0列中当遇到障碍物后则无法继续前进
    for(int i = 0; i < m; i++) {
        if(v[i][0]) {
            break;
        } else {

            step[i][0] = 1;
        }
    }

    // 同样第0行中若遇到障碍物也无法继续前进
    for(int i = 0; i < n; i++) {
        if(v[0][i]) {
            break;
        } else {
            step[0][i]  = 1;
        }
    }

    // 若当前位置有障碍物则不计入方法数中，否则的话当前位置的方法数就等于
    // 左边位置的方法数加上边位置的方法数
    for(int i = 1; i < m; i++)  {
        for(int j = 1; j < n; j++) {
            if(v[i][j]) {
                step[i][j] = 0;
            } else {
                step[i][j] = step[i-1][j] + step[i][j-1];
            }
        }
    }

    // 最终返回当大目的地时的方法总数
    return step[m-1][n-1];
}

int main()
{
    int n,m;
    vector<vector<int>> v;
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

       cout <<  step(v) << endl;
    }

    return 0;
}

