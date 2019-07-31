/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-31 15:34:40
 * Filename      : dp_11.cpp
 * Description   :懂爱规划练习11—— 最短编辑距离
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int minstep(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    if(str1.empty() || str2.empty()) {
        return max(len1, len2);
    }
    vector<vector<int> > step(len1, vector<int>(len2, 0));  // 用来存放每一步的编辑举例

    // 初始化
    for(int i = 0; i <= len1; i++) {
        step[i][0] = i;
    }
    for(int j = 0; j <= len2; j++) {
        step[0][j] = j;
    }

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(str1[i-1] == str2[j-1]) {
                // 如果str1的第i个字符与str2的第j个字符相等
                // 则编辑巨鹿不变
                step[i][j] = 1 + min(step[i-1][j], step[i][j-1]);
                step[i][j] = min(step[i][j], step[i-1][j-1]);
            } else {
                step[i][j] = min(step[i-1][j], step[i][j-1]) + 1;
                step[i][j] = min(step[i][j], 1 + step[i-1][j-1]);
            }
        }
    }
    return step[len1][len2];
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2) {
        cout << minstep(str1, str2) << endl;
    }
    return 0;
}

