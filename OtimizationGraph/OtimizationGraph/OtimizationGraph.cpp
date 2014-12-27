// OtimizationGraph.cpp : Defines the entry point for the console application.
//

#include <stdio.h>            /* C input/output                       */
#include <stdlib.h>           /* C standard library                   */
#include "stdafx.h"
#include "TravelingSalesmanSimplex.h"


int main(void)
{
	/*TravelingSalesmanSimplex* tss = new TravelingSalesmanSimplex(3);
	tss->AddVariable(1);
	tss->AddVariable(2);
	tss->AddVariable(3);
	tss->AddVariable(4);
	tss->AddVariable(5);
	tss->AddVariable(6);
	tss->AddVariable(7);
	tss->AddVariable(8);
	tss->AddVariable(9);
	tss->SetupConstraints();
	*///tss->SetupObjectiveFunction();
	//tss->WriteFile("teste");
	
	TravelingSalesmanSimplex* tss2 = new TravelingSalesmanSimplex("model.lp");
	//tss2->WriteFile("teste3");
	tss2->Solve();
	SalesmanGraph* sGraph = tss2->CreateGraph();
	sGraph->z = tss2->z;
	sGraph->WriteLaTex();
	sGraph->PrintGroups();

	delete(tss2);
	delete(sGraph);
	return 0;
}
