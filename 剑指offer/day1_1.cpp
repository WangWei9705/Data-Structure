/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-08-01 14:01:39
 * Filename      : day1_1.cpp
 * Description   : 剑指offer面试题1——赋值运算符重载
 * 1、返回值类型为类类型引用
 * 2、参数为const 类&
 * 3、检查是否自己给自己赋值
 * 4、返回值为*this
 * 5、如果牵扯到指针，需要释放内存，否则会导致内存泄漏
 * *******************************************************/
#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
    String(char* pData = nullptr)
        : _pData(pData)
    {
        if(pData != nullptr) {
            int len = strlen(pData);
            _pData = new char[len+1];
            strcpy(_pData, pData);
        }
    }

    String(const String& str) {
        int len = strlen(str._pData);
        _pData = new char[len+1];
        strcpy(_pData, str._pData);
    }

    String& operator= (const String& str) {
        if(this != &str) {

            // 使用拷贝构造函数创建一个临时实例
            String strTemp(str);
            char* pTemp = strTemp._pData;
            // 交换临时实例和原来的实例
            strTemp._pData = _pData;
            _pData = pTemp;
        }

        return *this;
    }

    void print() {
        cout << _pData << endl;
    }

    ~String() {
        if(_pData) {
            delete[] _pData;
        }
        _pData = nullptr;
    }
private:
        char* _pData;
};
class Data{
public:
    Data(int year)
        : _year(year)
    {}

    Data& operator= (const Data& d) {
        if(this != &d) {
            _year = d._year;
        }
        return *this;

    }

private:
    int _year;
};


void test() {
    char* test = "hello";

    String str1(test);
    String str2;
    str2 = str1;


    cout << test << endl;
    str1.print();
    str2.print();
}
int main()
{
    test();
    return 0;
}

