#include <iostream>
#include <vector>
#include <set>
#include <locale.h>
using namespace std;

bool isMarked(int* array, int size, int elem)
{
	for (int i = 1; i < size; i++)
		if (array[i] == elem)
			return 1;
	return 0;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	/*int V, ** cost, ** result;
	cout << "Количество вершин: ";
	cin >> V;
	cost = new int* [V];
	result = new int* [V];
	for (int i = 0; i < V; i++)
	{
		cost[i] = new int[V];
		result[i] = new int[V];
	}
	cout << "Матрица весов:" << endl;
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] == 0)
				cost[i][j] = INT_MAX;
			result[i][j] = 0;
		}
	set <int> visited, not_visited;
	visited.insert(0);
	for (int n = 1; n < V; n++)
		not_visited.insert(n);
	while (visited.size() != V)
	{
		int min = INT_MAX, index1, index2;
		for (auto i : visited)
		{
			for (auto j : not_visited)
			{
				if (cost[i][j] < min)
				{
					min = cost[i][j];
					index1 = i;
					index2 = j;
				}
			}
		}
		visited.insert(index2);
		not_visited.erase(index2);
		result[index1][index2] = cost[index1][index2];
		result[index2][index1] = cost[index1][index2];
	}

	cout << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << result[i][j] << ' ';
		cout << endl;
	}*/

	int V, ** cost;
	cout << "Количество вершин: ";
	cin >> V;
	cost = new int* [V + 1];
	for (int i = 0; i < V + 1; i++)
	{
		cost[i] = new int[V + 1];
	}
	cout << "Матрица весов:" << endl;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] == 0)
				cost[i][j] = INT_MAX;
		}
	int* marks;
	marks = new int[V + 1];
	marks[1] = 1;
	for (int n = 2; n <= V; n++)
		marks[n] = 0;
	int count = V - 1;
	while (count != 0)
	{
		int min = INT_MAX, str, col;
		for (int i = 1; i <= V; i++)
		{
			if (marks[i] != 0)
			{
				for (int j = 1; j <= V; j++)
				{
					if (marks[j] != 0)
						continue;
					else
					{
						if (cost[i][j] < min)
						{
							min = cost[i][j];
							str = i;
							col = j;
						}
					}
				}

			}
		}
		marks[col] = str;
		cost[col][str] = INT_MAX;
		count--;
	}

	cout << "Рёбра минимального остова: " << endl;
	for (int i = 2; i <= V; i++)
	{
		cout << "(" << i << ", " << marks[i] << ")  ";
	}
	cout << endl;
	system("pause");
}