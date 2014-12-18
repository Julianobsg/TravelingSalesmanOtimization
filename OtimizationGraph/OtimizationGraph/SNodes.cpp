#include "SNodes.h"


SNodes::SNodes()
{
	int group = 0;
}


SNodes::~SNodes()
{
}

void SNodes::AddEdge(SNodes* node)
{
	edge = node;
}

void SNodes::MakeGroupS(int actualGroup)
{
	this->group = actualGroup;
	if (edge->group < actualGroup)
	{
		edge->MakeGroupS(actualGroup);
	}
}
