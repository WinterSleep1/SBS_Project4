#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>
class LinearQueue
{
private:
	int rare;
	int front;

	T ary[SIZE];

public:
	LinearQueue()
	{
		rare = 0;
		front = 0;

		for (int i = 0; i < size; i++) { ary[i] = 0; }
	}

	void push(T data)
	{
		if (rare == SIZE) cout << "Over Flow" << endl;
		else			  ary[rare++] = data;
	}
	void pop()
	{
		if (empty()) cout << "Empty" << endl;
		else ary[front++] = NULL;
	}

	const T& front()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return ary[front];
		}
	}
	const int& Size()
	{
		return rare - front;
	}

	bool empty()
	{
		if (front == rare) return true;
		else return false;
	}
};

int main()
{
	LinearQueue<int> linearqueue;

	linearqueue.push(10);

	return 0;
}