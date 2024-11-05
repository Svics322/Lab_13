#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab13\Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestAddEdge)
        {
            Graph g(5);
            g.addEdge(0, 1);
            g.addEdge(0, 2);

            Assert::AreEqual(2, (int)g.adjList[0].size());
            Assert::AreEqual(1, g.adjList[0][0]);
            Assert::AreEqual(2, g.adjList[0][1]);
        }

        TEST_METHOD(TestColorGraph)
        {
            Graph g(5);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.addEdge(1, 2);
            g.addEdge(1, 3);
            g.addEdge(3, 4);

            vector<int> colors = g.colorGraph();

            Assert::IsTrue(colors[0] == 0);
            Assert::IsTrue(colors[1] != colors[0]);
            Assert::IsTrue(colors[2] != colors[0] && colors[2] != colors[1]);
            Assert::IsTrue(colors[3] != colors[1]);
            Assert::IsTrue(colors[4] != colors[3]);
        }


        TEST_METHOD(TestPrintAdjacencyMatrix)
        {
            Graph g(3);
            g.addEdge(0, 1);
            g.addEdge(0, 2);
            g.printAdjacencyMatrix();
        }
    };
}
