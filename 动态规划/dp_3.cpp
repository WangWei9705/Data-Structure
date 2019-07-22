/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-22 10:42:18
 * Filename      : dp_3.cpp
 * Description   : 动态规划练习3——求最大连续子数组之后
 * *******************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxsum(vector<int> v, int n) {
    if(n == 0) {
        return 0;
    }

    int sum = v[0];
    int max_sum = v[0];
    for(int i = 1; i < n; i++) {
        if(sum > 0) {
            sum += v[i];
        } else {
            sum = v[i];
        }

        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main()
{
    int n;
    while(cin >> n) {
        vector<int> v(n+1, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

       cout << maxsum(v, n) << endl;

    }

    return 0;
}

