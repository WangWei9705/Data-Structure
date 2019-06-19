/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-18 22:20:19
 * Filename      : insert_sort.c
 * Description   :插入排序 
 * *******************************************************/

#include <vector>
#include <iostream>
using namespace std;

void insert_sort(int* array, int n) {
    for(int i = 0; i < n; i++) {
        int key = array[i];
        int end = i-1;

        while(end >= 0 && key < array[end]) {
            array[end+1] = array[end];
            end--;
        }
        array[end+1] = key;
    }
}


int main() {
    int array[10] = {0};
    for(int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    insert_sort(array, 10);

    for(int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout <<endl;
    return 0;
}
