/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-08-01 14:55:20
 * Filename      : day1_2.cpp
 * Description   : 剑指offer面试题2——单例模式
 * 单例模式分为饿汉模式：在单例类定义时就会进行实例化
 * 和懒汉模式：只要到需要用到类的时候才会进行实例化
 *
 * 特点：访问量较少时使用懒汉模式，以时间换空间；访问量较大时
 * 或者访问的线程较多时需要使用饿汉模式，以空间换时间
 *
 * 实现单例模式的key point:
 * 1、线程安全
 * 2、构造函数声明为private 或者 protected房子被外部函数实例化
 * 3、内部需要维护一个 private static的指针
 * *******************************************************/
#include <iostream>
#include <pthread.h>
using namespace std;

// 线程安全的懒汉模式
// 方法一：使用互斥锁实现懒汉模式
class singleton1 {
protected:
    singleton1() {
        pthread_mutex_init(&mutex, NULL);
    }
private:
    static singleton1* p1;

public:
    static pthread_mutex_t mutex;
    static singleton1* instance();

};

pthread_mutex_t singleton1::mutex;
singleton1* singleton1::p1 = nullptr;;
singleton1* singleton1::instance() {
    if(p1 == nullptr) {
        // p1 为空说明实例还未创建，此时加锁
        // 保证接下来只有一个实例会被创建
        pthread_mutex_lock(&mutex);
        if(p1 == nullptr) {
            p1 = new singleton1();
        }

        // 创建完成之后解锁
        pthread_mutex_unlock(&mutex);
    }
    return p1;
}

// 方法2：使用内部静态变量实现懒汉模式
class singleton2{
protected:
    singleton2() {
        pthread_mutex_init(&mutex, NULL);
    }
public:
    static pthread_mutex_t mutex;
    static singleton2* instance();
};

pthread_mutex_t singleton2::mutex;
singleton2* singleton2::instance() {
    // 实例化之前加锁
    pthread_mutex_lock(&mutex);
    // 在instace函数里定义一个静态的实例，保证唯一拥有
    // 返回时只需要返回其指针即可
    static singleton2 obj;
    // 解锁
    pthread_mutex_unlock(&mutex);
    return &obj;

}

// 饿汉模式本身就是线程安全的，所以不用加锁
class singleton3 {
protected:
    singleton3() {}
private:
    static singleton3* p3;
public:
    static singleton3* instance();
};

singleton3* singleton3::p3 = new singleton3;
singleton3* singleton3::instance() {
    return p3;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

