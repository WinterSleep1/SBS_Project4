#include <iostream>

using namespace std;

template<typename T>
class CircleLinkedList
{
private:
	int size;

	struct Node
	{
		int data;
		Node* next;
	};

	Node* head;

public:
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		size++;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		size++;

		if (head == nullptr)	//	첫 생성
		{
			head = newNode;
			newNode->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}

	}

	void pop_back()
	{
		if (head == nullptr) cout << "pop_back : 노드가 없습니다." << endl;
		else
		{
			Node* deletedNode = head;
			Node* currentNode = head->next;

			if (head == nullptr) cout << "pop_back : 노드가 없습니다." << endl;
			else
			{
				if (head->next == head)	head = nullptr;		//	노드 1개
				else										//	2개 이상
				{	//	currentNode 가 head 의 뒤까지 이동
					while (currentNode->next != head) { currentNode = currentNode->next; }

					head = currentNode;
					head->next = deletedNode->next;
				}

				size--;
				delete deletedNode;
			}
		}

	}
	void pop_front()
	{
		if (head == nullptr) cout << "pop_front : 노드가 없습니다." << endl;	//	노드가 없음
		else																//	노드가 있음
		{
			Node* deletedNode = head->next;

			if (head == head->next) head = nullptr;					//	노드가 1개
			else					head->next = deletedNode->next;	//	노드가 2개 이상

			size--;
			delete deletedNode;
		}
	}

	void show_head()
	{
		Node* newNode = head->next;

		cout << "==============================" << endl;
		cout << "head :" << head << endl;
		cout << "head.data :" << head->data << endl;
		cout << "head.next :" << head->next << endl << endl;

		cout << "node1 :" << newNode << endl;
		cout << "node1.data :" << newNode->data << endl;
		cout << "node1.next :" << newNode->next << endl;
		cout << "==============================" << endl;
	}
	void show()
	{
		Node* newNode = head->next;

		for (int i = 0; i < size; i++)
		{
			cout << newNode->data << " ";
			newNode = newNode->next;
		}

		cout << endl;
	}
	const int& get_size()
	{
		return size;
	}

	~CircleLinkedList()
	{
		while (head != nullptr) { pop_front(); }
	}
};

int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);

	circleLinkedList.push_front(1);
	circleLinkedList.push_front(2);
	circleLinkedList.push_front(3);

	circleLinkedList.pop_back();
	circleLinkedList.pop_back();
	circleLinkedList.pop_back();
	circleLinkedList.pop_back();
	circleLinkedList.pop_back();
	circleLinkedList.pop_back();
	circleLinkedList.pop_back();

	circleLinkedList.show();
	cout << "size : " << circleLinkedList.get_size() << endl;

	return 0;
}