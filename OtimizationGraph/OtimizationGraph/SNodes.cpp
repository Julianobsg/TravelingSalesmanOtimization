#include "SNodes.h"


SNodes::SNodes()
{
	int group = 0;
	//edge = new list<SNodes*>();
}


SNodes::~SNodes()
{
}

void SNodes::AddEdge(SNodes* node)
{
	edge.push_back(node);
}

void SNodes::MakeGroupS(int actualGroup)
{
	this->group = actualGroup;
	for (list<SNodes*>::iterator it = edge.begin(); it != edge.end(); it++)
	{
		if ((*it)->group < actualGroup)
		{
			(*it)->MakeGroupS(actualGroup);
		}
	}

}
