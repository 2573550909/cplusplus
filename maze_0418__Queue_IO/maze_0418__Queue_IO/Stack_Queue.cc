#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
using namespace std;
#include <stack>
#include <queue>

//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����

//ջ�Ǹ�������Ҫ�������ݣ������int���͵�����
//std::stack<int>	s;
//	std		�����ռ�		namespace
//	<>		ģ����		

//	s.push(1);   ��Ͷ���
//	s.pop();
//	int v = s.top();
//	int size = s.size();
//	s.empy();
//	string �ַ�������

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> stack_ch;//����һ��ջ
		int size = s.size();//�����ַ����ĳ���
		for (int i = 0; i < size; ++i)
		{
			char ch = s[i];
			switch (ch)
			{
			case'(':
			case'[':
			case'{':
				stack_ch.push(ch);//ѹ��
				break;
			case')':
			case']':
			case'}':
			{
				if (stack_ch.empty())
				{
					return false;
				}
				char left = stack_ch.top();
				if (!((left == '('&& ch == ')') ||
					(left == '['&& ch == ']') ||
					(left == '{'&& ch == '}')))
				{
					return false;
				}
				stack_ch.pop();
				break;
			}
			default:
				break;
			}
		}
		if (!stack_ch.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

//�ö���ʵ��ջ
class MyStack {
public:
	queue<int>	q;//��Ա����
	
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
		for (int i = 0; i < size; ++i)
		{
			int data = q.front();
			q.pop();
			q.push(data);
		}
		int d = q.front();
		q.pop();
		return d;
	}

	/** Get the top element. */
	int top() {
		int size = q.size() - 1;
		for (int i = 0; i < size; ++i)
		{
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

//��ջʵ�ֶ���
class MyQueue {
public:
	stack<int> left;
	stack<int> right;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		right.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
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
		if (left.empty())
		{
			int size = right.size();
			for (int i = 0; i < size; ++i)
			{
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
		return left.empty() && right.empty();
	}
};


//ʵ��һ����Сջ
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int>	normal;
	stack<int>  min;
	MinStack() {
	}

	void push(int x) {
		normal.push(x);
		if (min.empty() || x <= min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};


//���ѭ������
class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	int* array;
	int size;
	int capacity;
	int front;//�����±�
	int rear;//��β�±�
	MyCircularQueue(int k) {
		array = new int[k];
		capacity = k;
		front = 0;
		rear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size == capacity)
		{
			return false;
		}
		array[rear] == value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size == 0)
		{
			return false;
		}
		front = (front + 1) % capacity;
		size--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size == 0)
		{
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size == 0)
		{
			return -1;
		}
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

int main()
{
	system("pause");
	return 0;
}