#pragma once
#include "SNodes.h"
#include <stdlib.h>
#include <stdio.h>

class SalesmanGraph
{
public:
	int size;
	int maxS;
	SNodes* nodes;
	void PrintGroups();
	SalesmanGraph(int size, double* edges);
	~SalesmanGraph();
};

