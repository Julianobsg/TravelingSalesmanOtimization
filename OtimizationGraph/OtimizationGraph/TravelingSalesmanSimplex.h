#pragma once
#include <string>

#include <lp_lib.h>
#include "SalesmanGraph.h"

using namespace std;

class TravelingSalesmanSimplex
{
public:
	double* solution;
	double z;
	void AddVariable(double value);
	void WriteFile(string fileName);
	void SetupObjectiveFunction();
	void SetupConstraints();
	SalesmanGraph* Solve();
	TravelingSalesmanSimplex(int variables);
	TravelingSalesmanSimplex(char* fileName);
	~TravelingSalesmanSimplex();
private:
	lprec *lp;
	int size;
	int lastInsertedVariable;
	int* colNumber;
	double* rows;
};

