#include "SalesmanGraph.h"


SalesmanGraph::SalesmanGraph(int size, double* edges)
{
	nodes = (SNodes*) malloc(size * sizeof(nodes));
	this->size = size;
	int i;
	int squareSize = size * size;

	for (i = 0; i < squareSize; i++)
	{
		if (edges[i] > 0)
		{
			int row, col;
			col = i % size;
			row = i / size;
			nodes[row].AddEdge(&nodes[col]);
		}
	}

	int actualGroup = 1;
	for (i = 0; i < size; i ++)
	{
		nodes[i].id = i + 1;
		if (nodes[i].group < 1)
		{
			nodes[i].MakeGroupS(actualGroup);
			actualGroup++;
		}
	}
	maxS = actualGroup;
}


SalesmanGraph::~SalesmanGraph()
{
}

void SalesmanGraph::PrintGroups()
{
	for (int i = 0; i < maxS; i++)
	{
		printf("S%d:", i);
		for (int j = 0; j < size; j++)
		{
			if (nodes[j].group == i + 1)
			{
				printf(" %d,", nodes[j].id);
			}
		}
		printf("\n");
	}
}
