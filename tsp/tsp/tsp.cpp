// tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "TspSolution.h"
#include "Util.h"
#include "TSPSolver.h"


using namespace std;
using namespace TSP;





long _tmain(long argc, _TCHAR* argv[])
{

	ifstream file;
	file.open("F:\\COURSES\\DIscreteOptimiz\\tsp\\data\\tsp_51_1");
	
	long n = 0;
	file >> n;
	_tpoints points;
	for (long i = 0; i< n; i++)
	{
		double x,y;
		file >> x >> y;
		points.push_back(make_pair(x,y));
	}
	try
	{
		TSPSolver solver(points);

		TspSolution* starting = solver.GetStartingSolution();
		TspSolution* opt = solver.Opt2(starting, 1000);
		
		opt->Print();
	
	}
	catch(exception e)
	{
		cout << e.what();
	}
	return 0;
}

