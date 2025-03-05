#include <iostream>

#define SIZE 6

using namespace std;

template<typename KEY, typename VALUE>
class Hashtable
{
private:

	struct Node
	{
		KEY key;
		VALUE value;
		Node* nextNode;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];
public:
	Hashtable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template<typename T>
	const int& HashFunction(T key)
	{
		unsigned int hashindex = (int)key % SIZE;
		return hashindex;
	}
	template<>
	const int& HashFunction(const char* key)
	{
		int hash = 0;

		for (int i = 0; i < strlen(key); i++)
		{
			hash += key[i];
		}

		unsigned int hashindex = hash % SIZE;

		return hashindex;
	}

	Node* creatNode(KEY k, VALUE v)
	{
		Node* newNode = new Node;

		newNode->key = k;
		newNode->value = v;
		newNode->nextNode = nullptr;

		return newNode;
	}

	void insert(KEY k, VALUE v)
	{
		int hashindex = HashFunction(k);

		Node* newNode = creatNode(k, v);

		if (bucket[hashindex].count == 0) bucket[hashindex].head = newNode;
		else
		{
			newNode->nextNode = bucket[hashindex].head;
			bucket[hashindex].head = newNode;
		}

		bucket[hashindex].count++;
	}
	void remove(KEY k)
	{
		int hashindex = HashFunction(k);

		Node* currentNode = bucket[hashindex].head;
		Node* previousNode = nullptr;

		if (currentNode == nullptr) return;
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == k)
				{
					if (currentNode == bucket[hashindex].head) bucket[hashindex].head = currentNode->nextNode;
					else previousNode->nextNode = currentNode->nextNode;

					bucket[hashindex].count--;

					delete currentNode;
					return;
				}
				else
				{
					previousNode = currentNode;
					currentNode = currentNode->nextNode;
				}
			}

			cout << "Not Found" << endl;
		}
	}

	~Hashtable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deletedNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr) continue;
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deletedNode->nextNode;

					delete deletedNode;

					deletedNode = nextNode;
				}
			}
		}

	}
};

int main()
{
	Hashtable<const char*, int> hashtable;

	hashtable.insert("sword", 100);
	hashtable.insert("armor", 200);

	hashtable.remove("armor");
	hashtable.remove("sword");
	hashtable.remove("abc");
}