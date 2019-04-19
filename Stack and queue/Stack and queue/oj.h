#pragma once
#include <string.h>

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

class Solution {
public:
	bool isValid(string s) {
		stack <char> s_ch;
		int size = s.size();

		for (int i = 0; i < size; i++){
			char ch = s[i];
			switch (ch){
			case '(':
			case '[':
			case '{':
				s_ch.push(ch);
				break;

			case ')':
			case ']':
			case '}': {
						  if (s_ch.empty()){
							  return false;
						  }

						  char left = s_ch.top();
						  if (!((left == '(' && ch == ')') ||
							  (left == '[' && ch == ']') ||
							  (left == '{' && ch == '}'))) {
							  return false;
						  }

						  s_ch.pop();
						  break;

			}
			default:
				break;

			}
		}

		if (!s_ch.empty()){
			return false;
		}

		return true;

	}
};



// 使用队列实现栈的下列操作：

// push(x) -- 元素 x 入栈
// pop() -- 移除栈顶元素
// top() -- 获取栈顶元素
// empty() -- 返回栈是否为空

class MyStack {    
public:
    queue <int> q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size()-1;
        for(int i = 0; i < size; i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        int d = q.front();
        q.pop();
        return d;
        
        
    }
    
    /** Get the top element. */
    int top() {
        int size = q.size()-1;
        for(int i = 0; i < size; i++ ){
            int data = q.front();
            q.pop();
            q.push(data);
        }
        
        int d = q.front();
        q.pop();
        q.push(d);
        return d;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 
 
// 使用栈实现队列的下列操作：

// push(x) -- 将一个元素放入队列的尾部。
// pop() -- 从队列首部移除元素。
// peek() -- 返回队列首部的元素。
// empty() -- 返回队列是否为空。
 
 
 class MyQueue {
public:
    stack <int> left;
    stack <int> right;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
         right.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(left.empty()){
            int size = right.size();
            for(int i = 0; i < size; i++){
                int d = right.top();
                right.pop();
                left.push(d);
            }
            
        }
        
        int v = left.top();
        left.pop();
        return v;
        
        
        
       
        
    }
    
    /** Get the front element. */
    int peek() {
        if(left.empty()){
            int size = right.size();
            for(int i = 0; i < size; i++){
                int d = right.top();
                right.pop();
                left.push(d);
            }
        }
        
        int v = left.top();
        return v;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(left.empty() && right.empty()){
            return true;
        }
        
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

 
 
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。

class MinStack {
public:
    
    
    stack <int> S;
    stack <int> s;
    /** initialize your data structure here. */
    MinStack() {
        
        
    }
    
    void push(int x) {
        S.push(x);
        if(s.empty() || s.top() > x){
            s.push(x);
        }
        
        else{
             s.push(s.top());
        }
        
       
        
    }
    
    void pop() {
        S.pop();
        s.pop();
        
    }
    
    int top() {
        return S.top();
        
    }
    
    int getMin() {
        return s.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

 
 // 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

// 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

// 你的实现应该支持如下操作：

// MyCircularQueue(k): 构造器，设置队列长度为 k 。
// Front: 从队首获取元素。如果队列为空，返回 -1 。
// Rear: 获取队尾元素。如果队列为空，返回 -1 。
// enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
// deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
// isEmpty(): 检查循环队列是否为空。
// isFull(): 检查循环队列是否已满。

class MyCircularQueue {
public:
    
    int *array;
	int capacity;
	int size;
	int front;	// 队首下标
	int rear;	// 队尾下标
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        array = new int [k];
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size == capacity){
            return false;
        }
        
        array[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size == 0){
            return false;
        }
        
        front = (front + 1) % capacity;
        size--;
        return true;
        
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return array[front];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        int index = (rear + capacity - 1) % capacity;
        
	    return array[index];
      
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


