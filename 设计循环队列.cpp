//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/design-circular-queue
MyCircularQueue {
private:
	vector<int> arr;
	int front;
	int rear;
	int capacity;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		rear = front = 0;
		capacity = k + 1;
		arr.resize(capacity, 0);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;
		arr[rear] = value;
		rear = (rear + 1) % capacity;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
			return false;
		front = (front + 1) % capacity;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
			return -1;
		return arr[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
			return -1;
		return arr[(rear - 1 + capacity) % capacity];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return front == rear;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return (rear + 1) % capacity == front;
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