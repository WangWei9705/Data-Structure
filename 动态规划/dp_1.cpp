/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-21 23:17:53
 * Filename      : dp_1.cpp
 * Description   : 动态规划练习1——斐波那契数列
 * *******************************************************/
#include <iostream>
using namespace std;

long long Fib(int n) {
    // 初始化
    long long f1 = 1;
    long long f2 = 1;
    long long ret = 0;   // 用户保存每次递归的结果
    // 状态方程
    for(int i = 3; i < n; i++) {
        ret = f1 + f2;
        f1 = f2;
        f2 =  ret;
    }
    return ret;
        
}

int main()
{
    int n;
    while(cin >> n) {
        cout << Fib(n) << endl;
    }
    return 0;
}

