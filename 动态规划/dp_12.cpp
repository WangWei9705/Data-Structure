/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-31 16:05:10
 * Filename      : dp_12.cpp
 * Description   : 动态规划练习12——求S中有多少个不同的子串与T相同
 * 例：S = "rabbbit"   T = "rabbit"  return 3;
 * 因为S中有三个b,可以组成三个不同的子序列构成T
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int GetSubsequece(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    // 如果str2的长度大于str1的长度则肯定无法通过str组成str2
    if(len2 > len1) {
        return 0;
    }

    // 如果str2为空，则str1中至少有一个字符个组成str2
    if(str2.empty()) {
        return 1;
    }

    vector<vector<int> > mat(len1+1, vector<int>(len2, 0));
    mat[0][0] = 1;
    for(int i = 1; i <= len1; i++) {
        mat[i][0] = i;
        for(int j = 1; j <= len2; j++) {
            if(str1[i-1] == str2[j-1]) {
                // 如果str1的第i个字符与str2的第j个字符相同
                // mat[i][j] = 上面的加左上角的
                mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
            } else {
                // 如果str1的第i个字符与str2的第j个字符不相同
                // mat[i][j] = 上面的
                mat[i][j] = mat[i-1][j];
            }
        }
    }
    return mat[len1][len2];

}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2) {
        cout << GetSubsequece(str1, str2) << endl;
    }
    return 0;
}

