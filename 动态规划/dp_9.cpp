/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-30 11:47:55
 * Filename      : dp_9.cpp
 * Description   : 动态规划练习9——背包问题
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

int maxvalue(int n, int m, vector<int>& A, vector<int>& V) {
    if(m < 1 || A.empty() || V.empty()) {
        return 0;
    }

    // 方法一：使用二维动态规划
    vector<vector<int> > current_value(n+1, vector<int>(m+1, 0));
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(A[i-1] > j) {
                current_value[i][j] = current_value[i-1][j];
            } else {
                int newvalue = current_value[i][j-A[i-1]] + V[i-1];
                current_value[i][j] = max(newvalue, current_value[i-1][j]);
            }
        }
    }

    return current_value[n][m];

    // 方法二：使用一维动态规划，节省空间
    vector<int> result(m+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = m; j > 0; j--) {
            if(A[i] > j) {
                result[j] = result[j];
            } else {
                int newValue = result[j-A[i]] + V[i];
                result[j] = max(newValue, result[j]);
            }
        } 
    }

    return result[m];
}
int main()
{
    int n, m;
    while(cin >> n >> m) {
        vector<int> V(n, 0);
        vector<int> A(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> A[i] >> V[i];
        }

        cout << maxvalue(n, m, A, V) << endl;
    }
    return 0;
}

