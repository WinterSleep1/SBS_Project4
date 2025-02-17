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
	//	앞에 생성
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		size++;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	//	뒤에 생성
	void push_back(T data)				//	가장 뒤에 생성
	{
		Node* newNode = new Node;
		newNode->data = data;
		size++;

		if (head == nullptr)	//	첫 노드 생성
		{
			head = newNode;

			newNode->next = nullptr;
		}
		else	 //	노드가 1개 이상
		{
			Node* currentNode = head;

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;

			newNode->next = nullptr;
			newNode->data = data;
		}
	}
	//	앞 노드 제거
	void pop_front()
	{
		if (head == nullptr) { cout << "삭제할 노드가 없음" << endl; }
		else
		{
			Node* deletedNode = head;
			head = deletedNode->next;
			size--;
			delete deletedNode;
		}
	}
	//	뒤 노드 제거
	void pop_back()
	{
		if (head == nullptr) cout << endl << "제거할 노드가 없음" << endl;
		else if (head->next == nullptr)		//	노드가 1개
		{
			Node* deletedNode = head;
			head = nullptr;
			delete deletedNode;
			size--;
		}
		else		//	노드가 2개 이상
		{
			Node* previousNode = head;				//	예비노드1
			Node* deletedNode = previousNode->next;	//	예비노드2

			while (deletedNode->next != nullptr)		//	마지막 노드까지 이동
			{
				deletedNode = deletedNode->next;
				previousNode = previousNode->next;
			}

			previousNode->next = nullptr;
			delete deletedNode;
			size--;
		}

		size--;
	}
	//	앞 노드부터 출력
	void show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}

		cout << endl;
	}

	//	size 출력
	const int& Size() { return size; }

	~SingleLinkedList()
	{
		while (head != nullptr) { pop_front(); }
	}

};

int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.push_front(10);
	singleLinkedList.push_front(20);	//	20 10

	singleLinkedList.push_back(5);
	singleLinkedList.push_back(10);

	singleLinkedList.show();		//	20 10 5 10
	cout << "size : " << singleLinkedList.Size() << endl;

	singleLinkedList.pop_back();		//	10 제거

	singleLinkedList.show();		//	20 10 5
	cout << "size : " << singleLinkedList.Size() << endl;

	return 0;
}
