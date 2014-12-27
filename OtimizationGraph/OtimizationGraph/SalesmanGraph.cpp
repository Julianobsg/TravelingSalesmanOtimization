#include "SalesmanGraph.h"
#include <string>

SalesmanGraph::SalesmanGraph(int size, REAL* edges)
{
	z = 0;
	nodes = new SNodes[size * size];
	this->size = size;
	int i;
	int squareSize = size * size;
	
	for (i = 0; i < squareSize; i++)
	{
		if (edges[i] > 0.01)
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
	this->edges = edges;
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

void SalesmanGraph::WriteLaTex()
{
	ofstream myfile;
	int angle = 360 / this->size;

	myfile.open("graphLatex.tex");
	string edgeText = "";
	myfile << "\\begin{table}[h]"  		   << "\n\\begin{tabular}{lllll}\n\n\n";
	int tabCounter = 0;
	for (int i = 0; i < size * size; i++)
	{
		if (edges[i] > 0.01)
		{
			int row, col;
			col = i % size;
			row = i / size;
			myfile << "$x_{" << to_string(nodes[row].id) << "\\_" << to_string(nodes[col].id)
				<< "} = " << to_string(edges[i]) << "$";
			if (tabCounter < 3)
			{
				myfile << "&";
				tabCounter++;
			}
			else
			{
				myfile << "\\\\\n";
				tabCounter = 0;
			}
			edgeText += "\\draw[->, >= latex](n-" 
				+ to_string(nodes[row].id) + ") -- (n-" + to_string(nodes[col].id) + ");\n";
		}
	}

	myfile << "\n\\end{tabular}"	       << "\n\\end{table}";

	myfile << "\n\\begin{tikzpicture}[transform shape]                                              "		<< "\n  %the multiplication with floats is not possible. Thus I split the loop in two.   "		<< "\n  \\tikzstyle{graphNode}=[draw,circle,thick,minimum size=6mm, inner sep = 0.25cm]  "		<< "\n    \\tikzstyle{red}=[graphNode,draw=red!75,fill=red!20]                           "		<< "\n    \\tikzstyle{blue}=[graphNode,draw=blue!75,fill=blue!20]                        "		<< "\n    \\tikzstyle{yellow}=[graphNode,draw=black!75,fill=yellow!20]                   "		<< "\n    \\tikzstyle{orange}=[graphNode,draw=orange!75,fill=orange!20]                  "		<< "\n    \\tikzstyle{gray}=[graphNode,draw=gray!75,fill=gray!20]                        "		<< "\n    \\tikzstyle{green}=[graphNode,draw=green!75,fill=green!20]                     "		<< "\n    \\tikzstyle{white}=[graphNode,draw=black!75,fill=white!20]                     "		<< "\n    \\tikzstyle{purple}=[graphNode,draw=black!75,fill=purple!20]                   "		<< "\n    \\tikzstyle{brown}=[graphNode,draw=black!75,fill=brown!20]                     ";

	myfile << "\n% desenhando grafo \n";

	for (int i = 0; i < size; i++)
	{
		string color = GetColor(nodes[i].group);
		myfile << "\\mycount = " << i << "\\advance\\mycount by - 1"
		<< "\\multiply\\mycount by " << angle
		<< "\\advance\\mycount by 22.5"
		<< "\n\\node[" << color.c_str()
		<< "](n-" << nodes[i].id << ") at(\\the\\mycount:5.4cm) {"
		<< nodes[i].id << "};"
		<< "\n";
	}
	myfile << edgeText;
	//myfile << "\\end{tikzpicture}";
	myfile << "\n	\\end{tikzpicture} \n %Colocando conjunto de soluçoes\n";
	const char* sSeparator = "";
	for (int i = 0; i < maxS -1; i++)
	{
		const char* separator = "";
		myfile << sSeparator << "$S_{" << i + 1 << "}(";
		for (int j = 0; j < size; j++)
		{
			if (nodes[j].group == (i + 1))
			{
				myfile << separator << nodes[j].id;
				separator = ",";
			}
		}
		myfile << ")$";
		sSeparator = ",";
	}

	myfile << "\n\nA função objetiva é: " << z << ".";
	/*myfile << "  \\foreach \\number in {1,...," << size << "}{\n"
	    << "\\mycount = \\number"
		<< "\\advance\\mycount by - 1"
		<< "\\multiply\\mycount by " << angle
		<< "\\advance\\mycount by 22.5"
		<< "\n\\node[draw, circle, inner sep = 0.25cm](N - \\number) at(\\the\\mycount:5.4cm) {};"
		<< "}\n";*/
	myfile.close();
}

string SalesmanGraph::GetColor(int group)
{
	string colors[10] = {"blue", "yellow", "red", "orange", 
		"gray", "green", "white", "purple", "brown", "gray" };
	return colors[group];
}
