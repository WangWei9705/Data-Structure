/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-22 18:19:01
 * Filename      : dp_5.cpp
 * Description   : 动态规划练习5——最短路径
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

int minstep(vector<vector<int>>& v) {
    if(v.empty()) {
        return 0;
    }

    vector<vector<int>> minstep(v);        // 用于保存0,0 到 i,j的路径和
    int row = v.size();

    // 从倒数第二行开始，可以不用考虑边界
    for(int i = row-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            minstep[i][j] = min(minstep[i+1][j], minstep[i+1][j+1]) + v[i][j];
        }
    }
    return minstep[0][0];
}
int main()
{
    int n,m;
    while(cin >> n >> m) {
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        cout << minstep(v) << endl;
    }
    return 0;
}

