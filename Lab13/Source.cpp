#include<Windows.h>

#include"Graph.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filePath;
	cout << "Введіть шлях з назвою файлу графа: ";
	getline(cin, filePath);

	Graph graph(0);

	if (!graph.readGraphFromFile(filePath)) {
		cerr << "Помилка при зчитуванні графа з файлу." << endl;
		return 1;
	}

	graph.printAdjacencyMatrix();

	vector<int> graphClrs = graph.colorGraph();
	size_t minClrsCount = *max_element(graphClrs.begin(), graphClrs.end()) + 1;
	
	cout << "Мінімальна кількість кольорів для розфарбування графа: "
		<< minClrsCount << endl;
	cout << "Розфарбовування вершин графа кольорами: " << endl;
	for (size_t i = 0; i < graph.N; i++)
		cout << "Вершина графа " << (i + 1) << ": "
		<< "отримує колір " << (graphClrs[i] + 1) << endl;
	return 0;
}