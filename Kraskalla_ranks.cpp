#include <iostream>
#include <vector>
#include <set>
#include <locale.h>
using namespace std;

int* parent, * ranks;

void make_set(int v) {
	parent[v] = v;
	ranks[v] = 0;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (ranks[a] < ranks[b])
			swap(a, b);
		parent[b] = a;
		if (ranks[a] == ranks[b])
			++ranks[a];
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int V, ** cost;
	pair <int, int>* skeleton;
	cout << "Количество вершин: ";
	cin >> V;
	cost = new int* [V];
	skeleton = new pair<int, int>[V - 1];
	for (int i = 0; i < V; i++)
	{
		cost[i] = new int[V];
	}
	cout << "Матрица весов:" << endl;
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] == 0)
				cost[i][j] = INT_MAX;
		}
	parent = new int[V];
	ranks = new int[V];
	for (int i = 0; i < V; i++)
		make_set(i);

	int N = V - 1;
	while (N > 0)
	{
		int min = INT_MAX, index1, index2;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (find_set(i) != find_set(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					index1 = i;
					index2 = j;
				}
			}
		}
		cost[index1][index2] = INT_MAX;
		cost[index2][index1] = INT_MAX;
		union_sets(index1, index2);
		skeleton[N - 1].first = index1;
		skeleton[N - 1].second = index2;
		N--;
	}

	cout << "Рёбра минимального остова: " << endl;
	for (int i = V - 2; i >= 0; i--)
	{
		//if (skeleton[i] != -1)
		cout << "(" << skeleton[i].first + 1 << ", " << skeleton[i].second + 1 << ")  ";
	}
	cout << endl;
	system("pause");
}