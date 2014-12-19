#include <list>
#pragma once
using namespace std;

class SNodes
{
public:
	int id;
	int group;
	list<SNodes*> edge;

	void AddEdge(SNodes* nodes);
	SNodes();
	~SNodes();
	void MakeGroupS(int actualGroup);
};

