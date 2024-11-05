#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;


class Graph {
public:
	int N, M;
	vector<vector<int>> adjList;
	
	Graph(int n);
	void addEdge(int u, int v);
	bool readGraphFromFile(const string& fileName);
	vector<int> colorGraph() const;
	void printAdjacencyMatrix() const;
};

Graph::Graph(int n) : M(0) {
	adjList.resize(n);
	N = n;
}

void Graph::addEdge(int u, int v) {
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

bool Graph::readGraphFromFile(const string& fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cerr << "Не вдалося відкрити файл." << endl;
		return false;
	}

	int n, m;
	file >> n >> m;

	if (n <= 0 || m <= 0) {
		cerr << "Кількість вершин і ребер повинно бути більше нуля." << endl;
		return false;
	}

	adjList.resize(n);

	for (int i = 0; i < m; i++) {
		int start, end;
		if (!(file >> start >> end)) {
			cerr << "Помилка при зчитуванні ребра." << endl;
			return false;
		}
		if (start < 1 || start > n || end < 1 || end > n) {
			cerr << "Помилка: невірні індекси ребра: "
				<< start << " -> " << end << endl;
		}
		addEdge(start - 1, end - 1);
	}
	file.close();
	this->N = n;
	this->M = m;
	return true;
}

vector<int> Graph::colorGraph() const {
	vector<int> colors(N, -1);
	colors[0] = 0;

	vector<bool> isAvbColor(N, false);
	for (int i = 1; i < N; i++) {
		for (int neighbor : adjList[i]) {
			if (colors[neighbor] != -1)
				isAvbColor[colors[neighbor]] = true;
		}

		int clr;
		for (clr = 0; clr < N; clr++)
			if (!isAvbColor[clr])
				break;

		colors[i] = clr;

		for (int neighbor : adjList[i])
			if (colors[neighbor] != -1)
				isAvbColor[colors[neighbor]] = false;
	}

	return colors;
}

void Graph::printAdjacencyMatrix() const {
	vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int neighbor : adjList[i])
			adjMatrix[i][neighbor] = 1;

	cout << "Матриця суміжності графа: " << endl;
	for (const auto& row : adjMatrix) {
		for (int val : row)
			cout << setw(5) << val << " ";
		cout << endl;
	}
}