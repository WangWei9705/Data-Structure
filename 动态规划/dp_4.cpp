/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-22 11:40:48
 * Filename      : dp_4.cpp
 * Description   : 动态规划练习4——分割字符串
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
        // 判空
        if(s.empty() || dict.empty()) {
            return false;
        }
        int maxlen = 0;
        unordered_set<string>::iterator it = dict.begin();
        for(; it != dict.end(); it++) {
            if((*it).size() > maxlen) {
                maxlen = (*it).size();
            }
        }
       
         
        vector<bool> v(s.size()+1, false);
        // 初始化
        v[0] = true;
         
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i-1; j >= 0; j--) {
                if((i-j) > maxlen) {
                    break;
                }
                 
                if(v[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    v[i] = true;
                    break;
                }
                 
            }
        }
         
        return v[v.size()-1];
         
}

int main()
{
    int n,m;
    string s;
    unordered_set<string> dict;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        cin >> m;
        string str;
        for(int i = 0; i < m; i++) {
            cin >> str;
            dict.insert(str);
        }

        cout << wordBreak(s, dict) << endl;

    }
    return 0;
}

