#pragma once
class SNodes
{
public:
	int id;
	int group;
	SNodes* edge;

	void AddEdge(SNodes* nodes);
	SNodes();
	~SNodes();
	void MakeGroupS(int actualGroup);
};

