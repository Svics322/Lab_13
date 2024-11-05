#include<Windows.h>

#include"Graph.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filePath;
	cout << "������ ���� � ������ ����� �����: ";
	getline(cin, filePath);

	Graph graph(0);

	if (!graph.readGraphFromFile(filePath)) {
		cerr << "������� ��� ��������� ����� � �����." << endl;
		return 1;
	}

	graph.printAdjacencyMatrix();

	vector<int> graphClrs = graph.colorGraph();
	size_t minClrsCount = *max_element(graphClrs.begin(), graphClrs.end()) + 1;
	
	cout << "̳������� ������� ������� ��� ������������� �����: "
		<< minClrsCount << endl;
	cout << "��������������� ������ ����� ���������: " << endl;
	for (size_t i = 0; i < graph.N; i++)
		cout << "������� ����� " << (i + 1) << ": "
		<< "������ ���� " << (graphClrs[i] + 1) << endl;
	return 0;
}