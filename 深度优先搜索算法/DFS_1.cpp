/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-28 22:31:31
 * Filename      : DFS_1.cpp
 * Description   : 扑克牌
 * 问题描述：有n张不重复的扑克牌放入n个盒子中，有多少中放法
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int>& poker, int index, int n, vector<int>& book) {
    // 判断边界
    if(index == n+1) {
        for(int i = 1; i <= n; i++) {
            cout << poker[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {
        // 如果i没放入则将其放入当前位置，同时标记为已使用
        if(book[i] == 0) {
            poker[index] = i;
            book[i] = 1;

            // 处理下一个盒子
            DFS(poker, index+1, n, book);

            // 回收
            book[i] = 0;
        }

    }
}

int main()
{
    int n;
    vector<int> poker;
    vector<int> book;
    cin >> n;
    poker.resize(n+1, 0);
    book.resize(n+1, 0);
    
    DFS(poker, 1, n, book);
    return 0;
}

