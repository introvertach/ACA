#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;

int** initCosts(int V, int E, int q, int r);

bool isMarked(int* array, int size, int elem);
int* Prima_marks(int V, int** cost);

int* parent, * ranks;
void make_set(int v);
int find_set(int v);
void union_sets(int a, int b);
pair <int, int>* Kraskalla_ranks(int V, int** cost);

int main()
{
	std::vector <pair<int, double>> res;
	int** cost;
	fstream file;
	file.open("1");

	int start, end;
	double time;

	/*for (int n = 1; n <= pow(10, 4) + 1; n += 100)
	{
		file << n << " ";
		cost = initCosts(n, n * n / 10, 1, pow(10, 6));

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << n << endl;
	} 

	for (int n = 101; n <= pow(10,4) + 1; n += 100)
	{
		file << n << " ";
		cost = initCosts(n, n * n, 1, pow(10, 6));

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << " > " << n << " < " << endl;
	} 

	for (int n = 101; n <= pow(10, 4) + 1; n += 100)
	{
		file << n << " ";
		cost = initCosts(n, 100 * n, 1, pow(10, 6));

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << n << endl;
	} 

	for (int n = 101; n <= pow(10, 4) + 1; n += 100)
	{
		file << n << " ";
		cost = initCosts(n, 1000 * n, 1, pow(10, 6));

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(n, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << n << endl;
	} 

	for (int m = 0; m <= 4000000; m += pow(10,5))
	{
		file << m << " ";
		cost = initCosts(10001, m, 1, pow(10, 6));

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << m << endl;
	} 

	for (int r = 1; r <= 200; r++)
	{
		file << r << " ";
		cost = initCosts(10001, pow(10001,2), 1, r);

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << r << endl;
	} 

	for (int r = 1; r <= 200; r++)
	{
		file << r << " ";
		cost = initCosts(10001, 10001 * 1000, 1, r);

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << " ";

		start = clock();
		Prima_marks(10001, cost);
		end = clock();
		time = double(end - start) / double(CLOCKS_PER_SEC);
		file << time << endl;
		cout << r << endl;
	} */
}

int** initCosts(int V, int E, int q, int r)
{
	int** cost;
	cost = new int* [V];
	for (int i = 0; i < V; i++)
		cost[i] = new int[V];

	if (E > V * (V - 1) / 2)
		E = V * (V - 1) / 2;

	for (int i = 0; i < V; i++)
		for (int j = i; j < V; j++)
		{
			if (j == i + 1)
			{
				if (E > 0)
				{
					cost[i][j] = rand() % r + q;
					E--;
				}
				else
					cost[i][j] = 0;
			}
			else
				cost[i][j] = 0;
		}

	int count = 0;
	if (V >= 3)
	while (E > 0)
	{
		int i = rand() % (V - 3);
		int j = (i + 2) + rand() % (V - i - 3);
		if (cost[i][j] != 0)
		{
			count++;
			continue;
		}
		else
		{
			cost[i][j] = rand() % r + q;
			E--;
			count--;
		}
		if (count > 100 * V)
			break;
	}

	return cost;
}

bool isMarked(int* array, int size, int elem)
{
	for (int i = 1; i < size; i++)
		if (array[i] == elem)
			return 1;
	return 0;
}


int* Prima_marks(int V, int** cost)
{
	int* marks;
	marks = new int[V];
	marks[0] = 1;
	for (int n = 1; n < V; n++)
		marks[n] = 0;

	int count = V - 1;
	while (count != 0)
	{
		int min = INT_MAX, str = 0, col = 0;
		for (int i = 0; i < V; i++)
		{
			if (marks[i] != 0)
			{
				for (int j = i; j < V; j++)
				{
					if (marks[j] != 0)
						continue;
					else
					{
						if (cost[i][j] < min && cost[i][j] != 0)
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

	return marks;
}

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

pair <int, int>* Kraskalla_ranks(int V, int** cost)
{
	pair <int, int>* skeleton;
	skeleton = new pair<int, int>[V - 1];

	parent = new int[V];
	ranks = new int[V];
	for (int i = 0; i < V; i++)
		make_set(i);

	int N = V - 1;
	while (N > 0)
	{
		int min = INT_MAX, index1 = 0, index2 = 0;
		for (int i = 0; i < V; i++)
		{
			for (int j = i; j < V; j++)
			{
				if (find_set(i) != find_set(j) && cost[i][j] < min && cost[i][j] != 0)
				{
					min = cost[i][j];
					index1 = i;
					index2 = j;
				}
			}
		}
		cost[index1][index2] = 0;
		//cost[index2][index1] = 0;
		union_sets(index1, index2);
		skeleton[N - 1].first = index1;
		skeleton[N - 1].second = index2;
		N--;
	}

	return skeleton;
}