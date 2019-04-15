// 使用队列实现栈



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
		int size = q.size() - 1;
		for (int i = 0; i < size; i++){
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
		int size = q.size() - 1;
		for (int i = 0; i < size; i++){
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