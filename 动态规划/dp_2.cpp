/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-21 23:30:03
 * Filename      : dp_2.cpp
 * Description   : 动态规划练习2——变态青蛙跳台阶
 * 思路：此题为斐波那契数列变形
 * *******************************************************/
#include <iostream>
using namespace std;


// 正常青蛙
long long Func(int n) {
    if(n == 1 || n == 0) {
        return 1;
    }else if(n == 2) {
        return 2;
    }
    // 初始化
    long long  f1 = 1;
    long long  f2 = 2;

    // 用于存储跳上上一级台阶的方法数
    long long ret = 0;
    for(int i = 3; i <= n; i++) {
        // 状态转移方程：F(n) = F(n-1) + F(n-2);
        ret = f1 + f2;
        f1 = f2;
        f2 = ret;
    }
    return ret;
}

// 变态青蛙
// f(1) = 1; f(2) = 2; f(3) = 4... f(n) = 2*f(n-1)/ 2^(n-1)
long long Func2(int n) {
    if(n < 2) {
        return 1;
    }
    // 初始化
    long long f1 = 1;

    long long ret = 1;
    for(int i = 2; i < n; i++) {
        ret *= f1;
        f1 = ret;
    }
    return ret;
}
int main()
{
    int n;
    while(cin >> n) {
        cout << Func(n) << endl;
    }
    return 0;
}

