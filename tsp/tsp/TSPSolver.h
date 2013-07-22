#pragma once
#include "TspSolution.h"
#include "Util.h"


class TSPSolver
{
public:
	TSPSolver(_tpoints points);
	~TSPSolver();
	TSP::TspSolution* BasicGreedy();
	TSP::TspSolution* JitGreedy(long starting_point = 0);
	TSP::TspSolution* GetStartingSolution();
	TSP::TspSolution* TSPSolver::Opt2(TSP::TspSolution* starting, long iterations);
	
private:
	void InitDistanceMatrix();

	_tpoints points;
	_tpoints::size_type num_points;
	vector<vector<double> >* distanceMatrix;
	vector<vector<pair<long,double> > >* sortedDistanceMatrix;
};

