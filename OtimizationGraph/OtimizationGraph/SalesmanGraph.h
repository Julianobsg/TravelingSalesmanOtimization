#pragma once
#include "SNodes.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <lp_lib.h>

using namespace std;

class SalesmanGraph
{
public:
	int size;
	int maxS;
	SNodes* nodes;
	void PrintGroups();
	void WriteLaTex();
	SalesmanGraph(int size, REAL* edges);
	~SalesmanGraph();
private:
	string GetColor(int id);
	REAL* edges;
};

