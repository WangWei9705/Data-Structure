/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-28 23:21:21
 * Filename      : DFS_2.cpp
 * Description   : 员工重要性
 * *******************************************************/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int DFS(unordered_map<int, Employee*>& info, int id) {
        
        int ret = info[id]->importance;
        for(const auto& sid : info[id]->subordinates) {
            ret += DFS(info, sid);
        }
        return ret;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty()) {
            return 0;
        }
        unordered_map<int, Employee*> info;
        
        for(const auto& e : employees) {
            info[e->id] = e;
        }
        return DFS(info, id);
        
    }
};
