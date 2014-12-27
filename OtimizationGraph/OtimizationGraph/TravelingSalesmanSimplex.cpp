#include "TravelingSalesmanSimplex.h"


TravelingSalesmanSimplex::TravelingSalesmanSimplex(int variables)
{
	int totalSize = variables * variables;
	lp = make_lp(0, totalSize);
	this->size = variables;
	lastInsertedVariable = 0;
	rows = (double*)malloc(totalSize * sizeof(rows));
	colNumber = (int *)malloc(totalSize * sizeof(rows));
	//printf("Size: %d\n", size);
}

TravelingSalesmanSimplex::TravelingSalesmanSimplex(char* fileName)
{
	lp = read_LP(fileName, NORMAL, "Traveling salesman");
	int totalSize = get_Ncolumns(lp);

    this->size = static_cast<int>(sqrt(totalSize));
	lastInsertedVariable = 0;
	rows = (double*)malloc(totalSize * sizeof(rows));
	solution = (double*)malloc(totalSize * sizeof(solution));
	colNumber = (int *)malloc(totalSize * sizeof(rows));
}


TravelingSalesmanSimplex::~TravelingSalesmanSimplex()
{
	//free(colNumber);
	//free(rows);
	//free(solution);
	delete_lp(lp);
}

void TravelingSalesmanSimplex::AddVariable(double value)
{
	lastInsertedVariable++;
	int row, col;
	col = ((lastInsertedVariable - 1) % size);
	row = ((lastInsertedVariable - 1)/ size);

	col++;
	row++;
	char variableName[8] = "x";
	sprintf_s(variableName, "x%d_%d", row, col);
	//printf("Lastiv: %d rol: %d col: %d\n", lastInsertedVariable, row, col);
	set_col_name(lp, lastInsertedVariable, variableName);
	colNumber[lastInsertedVariable - 1] = lastInsertedVariable;
	rows[lastInsertedVariable - 1] = value;
}

void TravelingSalesmanSimplex::WriteFile(string fileName)
{
	fileName += ".lp";
	char *cFileName = new char[fileName.length() + 1];
	strcpy_s(cFileName, 30, fileName.c_str());
	
	write_lp(lp, cFileName);
}

void TravelingSalesmanSimplex::SetupConstraints()
{
	int* colno;
	REAL* row;
	colno = (int *)malloc(size * sizeof(*colno));
	row   = (REAL *)malloc(size * sizeof(*row));

	for (int i = 0; i < size; i++)
	{
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				//printf("-");
				colno[k] = ((i * size) + j) + 1;
				row[k] = 1;
				k++;
			}
			//printf("i: %d - j: %d - (i * size) + j: %d\n", i, j, (i * size) + j );
		}
		//printf("K: %d\n", k);
		add_constraintex(lp, k, row, colno, EQ, 1);
	}
	for (int i = 0; i < size; i++)
	{
		int k = 0;
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				//printf("-");
				colno[k] = ((j * size) + i) + 1;
				row[k] = 1;
				k++;
			}
			//printf("i: %d - j: %d - (i * size) + j: %d\n", i, j, (i * size) + j );
		}
		//printf("K: %d\n", k);
		add_constraintex(lp, k, row, colno, EQ, 1);
	}
}

void TravelingSalesmanSimplex::Solve()
{

	set_minim(lp);

	//set_verbose(lp, NORMAL);

	if (solve(lp) != OPTIMAL)
	{
		printf("Error in solving the problem");
		return;
	}
	get_variables(lp, solution);


	z = get_objective(lp);
    printf("Objective value: %f\n", z);

	//for (int j = 0; j < size * size; j++)
	//	printf("%s: %f\n", get_col_name(lp, j + 1), solution[j]);

}

void TravelingSalesmanSimplex::SetupObjectiveFunction()
{
	set_obj_fnex(lp, lastInsertedVariable, rows, colNumber);
}

SalesmanGraph* TravelingSalesmanSimplex::CreateGraph()
{
	return new SalesmanGraph(size, solution);
}
