#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
const int maxV = 1000;
int i, j, n;
int GR[7][7] = {
	{ 0, 3, 0, 0, 0, 2, 0 },
	{ 3, 0, 7, 2, 0, 0, 0 },
	{ 1, 7, 0, 0, 0, 0, 0 },
	{ 0, 4, 0, 0, 5, 0, 0 },
	{ 0, 0, 0, 4, 0, 1, 0 },
	{ 0, 0, 0, 0, 3, 0, 3 },
	{ 8, 0, 0, 0, 0, 9, 0 } };

//алгоритм Флойда-Уоршелла
void FU(int D[][7], int V)
{
	int k;
	for (i = 0; i < V; i++) D[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
						D[i][j] = D[i][k] + D[k][j];

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	}
}

struct Edge {
	int begin;
	int end;
};

int main() {

	setlocale(LC_ALL, "Rus");

	// Отображение графа

	cout << "Исходный граф" << endl;
	cout << "| |1|2|3|4|5|6|7|" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "|" << i + 1 << "|";
		for (int j = 0; j < 7; j++)
		{
			cout << GR[i][j] << "|";
		}
		cout << endl;
	}
	cout << endl;

	// Поиск кратчайшего пути от A до B

	queue<int> Queue;
	stack<Edge> Edges;
	int req, req_2;
	Edge e;
	int min = 999;
	int min_counter = 0;
	int min_j = 0;
	
	int nodes[7]; // вершины графа
	for (int i = 0; i < 7; i++) // исходно все вершины равны 0
		nodes[i] = 0;

	cout << "Путь от вершины: ";
	cin >> req_2;
	req_2--;
	cout << "до вершины: ";
	cin >> req;
	req--;
	cout << endl;


	Queue.push(req_2); // помещаем в очередь первую вершину
	while (!Queue.empty())
	{
		int node = Queue.front(); // извлекаем вершину
		Queue.pop();
		nodes[node] = 2; // отмечаем ее как посещенную
		for (int j = 0; j < 7; j++)
		{
			if (GR[node][j] != 0 && nodes[j] == 0)
			{ // если вершина смежная и не обнаружена
				if (GR[node][j] < min)
				{
					min = GR[node][j];
					min_j = j;
				}
				Queue.push(j); // добавляем ее в очередь
				nodes[j] = 1; // отмечаем вершину как обнаруженную
				e.begin = node; e.end = j;
				Edges.push(e);
				if (node == req) break;
			}
		}
	}

	cout << "Путь до вершины " << req + 1 << endl;
	cout << req + 1;
	while (!Edges.empty()) {
		e = Edges.top();
		Edges.pop();
		if (e.end == req) {
			req = e.begin;
			cout << " <- " << req + 1;
		}
	}
	cout << endl;
	cout << endl;
	
	// Алгоритм Флойда
	cout << "Матрица кратчайших путей:" << endl;
	FU(GR, 7);
	system("pause>>void");
}
