#pragma once
#include <string.h>

//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����

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



// ʹ�ö���ʵ��ջ�����в�����

// push(x) -- Ԫ�� x ��ջ
// pop() -- �Ƴ�ջ��Ԫ��
// top() -- ��ȡջ��Ԫ��
// empty() -- ����ջ�Ƿ�Ϊ��

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
 
 
// ʹ��ջʵ�ֶ��е����в�����

// push(x) -- ��һ��Ԫ�ط�����е�β����
// pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
// peek() -- ���ض����ײ���Ԫ�ء�
// empty() -- ���ض����Ƿ�Ϊ�ա�
 
 
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

 
 
// ���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

// push(x) -- ��Ԫ�� x ����ջ�С�
// pop() -- ɾ��ջ����Ԫ�ء�
// top() -- ��ȡջ��Ԫ�ء�
// getMin() -- ����ջ�е���СԪ�ء�

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

 
 // ������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

// ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

// ���ʵ��Ӧ��֧�����²�����

// MyCircularQueue(k): �����������ö��г���Ϊ k ��
// Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
// Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
// enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
// deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
// isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
// isFull(): ���ѭ�������Ƿ�������

class MyCircularQueue {
public:
    
    int *array;
	int capacity;
	int size;
	int front;	// �����±�
	int rear;	// ��β�±�
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


