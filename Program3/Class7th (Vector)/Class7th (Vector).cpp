#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	int size;
	int capacity;

	T* container;

public:
	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;
	}

	void push_back(T data)
	{
		if (capacity <= 0) resize(1);
		else if (size >= capacity) resize(capacity * 2);

		container[size++] = data;
	}
	void pop_back()
	{
		if (size <= 0) cout << "Empty" << endl;
		else container[--size] = NULL;
	}
	void resize(int newSize)
	{
		T* newContainer = new T[newSize];
		capacity = newSize;

		for (int i = 0; i < capacity; i++) { newContainer[i] = NULL; }

		for (int i = 0; i < size; i++) { newContainer[i] = container[i]; }


		if (container != nullptr) delete[] container;

		container = newContainer;
	}

	const int& getSize()
	{
		return size;
	}
	const T& operator [] (const int& index)
	{
		return container[index];
	}

	~Vector()
	{
		if (container != nullptr) delete container;
	}
};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	vector.pop_back();

	for (int i = 0; i < vector.getSize(); i++) { cout << vector[i] << " "; }

	return 0;
}