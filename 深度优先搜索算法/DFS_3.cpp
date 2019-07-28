/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-28 23:43:21
 * Filename      : DFS_3.cpp
 * Description   : 图像渲染
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std; 
class Solution {
public:

    // 四个方向
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void DFS(vector<vector<int>>& image, int sr, int sc, int row, int col, int newColor, int oldColor, vector<vector<int>>& book) {
       // 将当前位置用新颜色填充，并标记为已填充
        image[sr][sc] = newColor;
        book[sr][sc] = 1;
        
        // 遍历四个方向进行填充
        for(int i = 0; i < 4; i++) {
            int nx = sr + dir[i][0];
            int ny = sc + dir[i][1];
            
            // 如果当前位置没有越界，同时当前位置未填充就进行神父有限搜索进行填充
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && image[nx][ny] == oldColor && book[nx][ny] == 0) {
                DFS(image, nx, ny, row, col, newColor, oldColor, book);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty()) {
            return image;
        }
        
        int row = image.size();
        int col = image[0].size();
        
        vector<vector<int>> book(row, vector<int>(col, 0));

        // 获取当前颜色
        int oldColor = image[sr][sc];
        
        // 进行颜色填充
        DFS(image, sr, sc, row, col, newColor, oldColor, book);
        return image;
       
        
    }
};


int main() {
	return 0;
} 
