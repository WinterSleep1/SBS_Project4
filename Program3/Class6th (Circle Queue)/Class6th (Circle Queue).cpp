#include <iostream>

#define SIZE 4

using namespace std;

template<typename T>
class CircleQueue
{
private:
	int front;
	int rear;
	T ary[SIZE];

public:
	CircleQueue()
	{
		rear = SIZE - 1;
		front = SIZE - 1;
		for (int i = 0; i < SIZE; i++) { ary[i] = NULL; }
	}

	void Push(T data)
	{

	}

	void Pop()
	{

	}
	bool Empty()
	{

	}
	const T& Front()
	{

	}
	const int& Size()
	{

	}
};

int main()
{
	CircleQueue<int> circlequeue;



	return 0;
}