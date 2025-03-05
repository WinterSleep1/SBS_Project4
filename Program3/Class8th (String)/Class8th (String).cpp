#include <iostream>

using namespace std;

class String
{
private:
	int size;
	char* ptr;

public:
	String()
	{
		size = 0;
		ptr = nullptr;
	}

	const int& get_size()
	{
		return size;
	}

	const void operator= (const char* word)
	{
		size = strlen(word) + 1;

		if (ptr == nullptr)
		{
			ptr = new char[size];
			for (int i = 0; i < size; i++) { ptr[i] = word[i]; }
		}
		else
		{
			char* newptr = new char[size];

			for (int i = 0; i < size; i++) { newptr[i] = word[i]; }

			delete[] ptr;

			ptr = newptr;
		}
	}

	const void append(const char* word)
	{
		size = size + strlen(word);

		char* newstring = new char[size + 1];		//	마지막에 NULL 포함

		for (int i = 0; i < size; i++)
		{
			if (i < strlen(ptr)) newstring[i] = ptr[i];		//	strlen(ptr) == 5 라면
			else				 newstring[i] = word[i - strlen(ptr)];	//	i == 5 이상
		}

		delete[] ptr;

		ptr = newstring;
	}

	unsigned long long find(const char* word)
	{

		int len = size - strlen(word);

		int i = 0, j = 0;

		for (i < len; i++;)
		{
			for (j < strlen(word); j++;)
			{
				if (ptr[i + j] != word[j]) break;
			}

			if (j == strlen(word)) return i;
		}
		return 18446744073709551615;
	}

	const char& operator [] (const int& index)
	{
		return ptr[index];
	}

	~String()
	{
		if (ptr != nullptr) delete[] ptr;
	}
};

int main()
{
	String string;
	string = "hello ";

	string.append("world");

	// for (int i = 0; i < string.get_size(); i++) { cout << string[i]; }

	// cout << endl << "size : " << string.get_size() << endl;

	cout << string.find("he") << endl;

	return 0;
}