#pragma once
#include <string>

#include <lp_lib.h>
#include "SalesmanGraph.h"

using namespace std;

class TravelingSalesmanSimplex
{
public:
	double z;
	void AddVariable(double value);
	void WriteFile(string fileName);
	void SetupObjectiveFunction();
	void SetupConstraints();
	void Solve();
	SalesmanGraph* CreateGraph();
	TravelingSalesmanSimplex(int variables);
	TravelingSalesmanSimplex(char* fileName);
	~TravelingSalesmanSimplex();
private:
	lprec *lp;
	int size;
	int lastInsertedVariable;
	int* colNumber;
	double* rows;
	REAL *solution;
};

