#include <iostream>

#define SIZE 10

using namespace std;

template<typename T>
class AdjacencyMatrix
{
private:
	int count;				//	정점 개수
	T vertex[SIZE];			//	정점 집합
	int matrix[SIZE][SIZE];	//	인접 행렬

public:
	AdjacencyMatrix()
	{
		count = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = 0;
			for (int j = 0; j < SIZE; j++) { matrix[i][j] = NULL; }
		}
	}

	void push(T data)
	{
		if (count >= SIZE) cout << "Size Over Flow" << endl;
		else
		{
			vertex[count] = data;
			count++;
		}
	}

	void edge(int i, int j)
	{
		if (i >= SIZE || j >= SIZE || count == 0)  cout << "Index Over Flow" << endl;
		else
		{
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	void show()
	{
		cout << " │" << vertex[0] << " " << vertex[1] << " " << vertex[2] << " " << endl;
		cout << "─┼──────" << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << vertex[i] << "│";

			for (int j = 0; j < 3; j++) { cout << matrix[i][j] << " "; }

			cout << endl;
		}
	}
};

int main()
{
	AdjacencyMatrix<char> adjacencyMatrix;

	adjacencyMatrix.push('A');
	adjacencyMatrix.push('B');
	adjacencyMatrix.push('C');

	adjacencyMatrix.edge(0, 1);
	adjacencyMatrix.edge(2, 1);

	adjacencyMatrix.show();

	return 0;
}