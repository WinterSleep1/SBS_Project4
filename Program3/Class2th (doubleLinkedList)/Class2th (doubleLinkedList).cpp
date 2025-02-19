#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	int size;

	struct Node
	{
		Node* preview;
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->preview = nullptr;
		newNode->next = nullptr;

		if (head == nullptr)	//	노드가 없으면
		{
			head = newNode;
			tail = newNode;
		}
		else		//	노드가 2개 이상
		{
			newNode->next = head;

			head->preview = newNode;
			head = newNode;
		}

		size++;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->preview = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;

		}
		else
		{
			tail->next = newNode;
			newNode->preview = tail;
			tail = newNode;
		}

		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "pop_front() : 노드가 없음" << endl;
		}
		else
		{
			Node* deletedNode = head;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
				size--;
			}
			else
			{
				deletedNode->next->preview = nullptr;
				head = head->next;
				size--;
			}
			delete deletedNode;
		}
	}
	void pop_back()
	{
		Node* deletedNode = tail;

		if (head == nullptr) cout << "pop_back : 노드가 없음" << endl;
		else if (head == tail)	//	노드가 1개
		{
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			tail = deletedNode->preview;
			deletedNode->preview->next = nullptr;
			size--;
		}
		delete deletedNode;
	}
	const int& get_size()
	{
		return size;
	}
	void show()
	{
		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}

	~DoubleLinkedList()
	{
		while (head != nullptr) { pop_front(); }
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.push_front(10);
	doubleLinkedList.push_front(20);
	doubleLinkedList.push_front(30);
	doubleLinkedList.push_front(40);

	doubleLinkedList.pop_front();

	doubleLinkedList.push_back(1);
	doubleLinkedList.push_back(2);
	doubleLinkedList.push_back(3);
	doubleLinkedList.push_back(4);

	doubleLinkedList.pop_back();
	doubleLinkedList.pop_back();

	cout << "size : " << doubleLinkedList.get_size() << endl;
	doubleLinkedList.show();

	return 0;
}