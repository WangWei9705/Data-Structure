/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-31 10:50:06
 * Filename      : dp_10.cpp
 * Description   : 动态规划练习10——切割回文串最小次数
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 方法一:结果复杂度为O(n^3)
bool IsHuiWen(string s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

// 方法二:由于已经将判断回文串的结果存在数组中，所以整体复杂度为O(n^2)
vector<vector<bool> > Getmat(string s) {
    int len = s.size();
    vector<vector<bool> > mat(len, vector<bool>(len, false));
    for(int i = len-1; i >= 0; i--) {
        for(int j = i; j < len; j++) {
            if(i == j) {
                mat[i][j] = true;
            } else if(j == i+1) {
                mat[i][j] = (s[i] == s[j]);
            } else {
                mat[i][j] = ((s[i] == s[j]) && mat[i+1][j-1]);
            }
        }
    }
    return mat;
}

int minCut(string s) {
    if(s.empty()) {
        return 0;
    }
    int len = s.size();
    vector<int> cut;
    for(int i = 0; i < len+1; i++) {
        // 首项为-1
        cut.push_back(i-1);
    }

    vector<vector<bool> > mat = Getmat(s);
    for(int i = 1; i < len+1; i++) {
        for(int j = 0; j < i; j++) {
            // if(IsHuiWen(s, j, i-1))
            if(mat[j][i-1]) {
                cut[i] = min(cut[i], cut[j]+1);
            }
        }
    }
    return cut[len];
}
int main()
{
    string s;
    while(cin >> s) {
        cout << minCut(s) << endl;
    }

    return 0;
}

