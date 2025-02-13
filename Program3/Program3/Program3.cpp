#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void push_front(T data)		//	가장 앞에 생성
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;	
			size++;
		}
	}

	void push_back(T data)		//	가장 뒤에 생성
	{
		Node* newNode = new Node;
		Node* currentNode;

		newNode->data = data;

		if (head == nullptr)			//	첫 생성
		{
			head = newNode;

			newNode->next = nullptr;
		}
		else
		{

		}
	}

	// ~SingleLinkedList() {}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.push_front(10);
	singleLinkedList.push_front(20);

	cout <<  << endl;

	return 0;
}
