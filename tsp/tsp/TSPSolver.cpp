#include "TSPSolver.h"


TSPSolver::TSPSolver(_tpoints pts)
	: points(pts), num_points(pts.size()), distanceMatrix(NULL), sortedDistanceMatrix(NULL)
{
}


TSPSolver::~TSPSolver(void)
{
	if (distanceMatrix)
		delete distanceMatrix;
	if (sortedDistanceMatrix)
		delete sortedDistanceMatrix;
}

TSP::TspSolution* TSPSolver::JitGreedy(long starting_point)
{
	long n = points.size();
	vector<long> avail_points = vector<long>(n,1);
	
	//vector<vector<double> > distanceMatrix(n, vector<double>(n));
	//BuildDistanceMatrix(points, distanceMatrix);
	//PrintMatrix(distanceMatrix);

	//vector<vector<pair<long,double> > > sortedDistanceMatrix(n, vector<pair<long,double>>(n));
	//SortDistanceMatrix(distanceMatrix, sortedDistanceMatrix);
	//PrintPointMatrix(sortedDistanceMatrix);


	long last_choosen = starting_point;
	TSP::TspSolution* solution = new TSP::TspSolution(last_choosen);
	avail_points[last_choosen] = 0;

	// we need to select n-1 point to build a tour

	for (long i = 0; i < n-1; i++)
	{
		// we need to buid a distance vector and a sorted distance vector
		vector<double> distanceVector(n);
		BuildDistanceVector(last_choosen, points, distanceVector);
		
		vector<pair<long, double>> sortedDistanceVector(n);
		SortDistanceVector(distanceVector, sortedDistanceVector);

		// theese are dictances from last point in a tour
		//vector<vector<pair<long,double> > >::iterator vec_distances = sortedDistanceMatrix.begin() + last_choosen;
		vector<pair<long,double> >::const_iterator it = sortedDistanceVector.begin();
		while (avail_points[it->first] == 0 || it->second == 0 )
		{
		it++;
		}
		solution->AddPoint(it->first, it->second);
		avail_points[it->first] = 0;
		long point_to_delete = it->first;
		last_choosen = it->first;
		//DeletePointFromSortedmatrix(it->first, sortedDistanceMatrix);

	}
	solution->MakeCycle(points);
	return solution;
}

TSP::TspSolution* TSPSolver::BasicGreedy()
{

	vector<long> avail_points = vector<long>(num_points,1);
	
	InitDistanceMatrix();

	long last_choosen = 0;
	TSP::TspSolution* solution = new TSP::TspSolution(last_choosen);
	avail_points[last_choosen] = 0;

	// we need to select num_points-1 point to build a tour

	for (long i = 0; i < num_points-1; i++)
	{
		// theese are dictances from last point in a tour
		vector<vector<pair<long,double> > >::iterator vec_distances = sortedDistanceMatrix->begin() + last_choosen;
		vector<pair<long,double> >::const_iterator it = vec_distances->begin();
		while (avail_points[it->first] == 0 || it->second == 0 )
		{
		it++;
		}
		solution->AddPoint(it->first, it->second);
		avail_points[it->first] = 0;
		long point_to_delete = it->first;
		last_choosen = it->first;
		DeletePointFromSortedmatrix(it->first, *sortedDistanceMatrix);

	}
	solution->MakeCycle(points);
	return solution;
}

TSP::TspSolution* TSPSolver::GetStartingSolution()
{
	TSP::TspSolution* opt = new TSP::TspSolution(0);
	vector<pair<double,double>>::size_type num_points = points.size();

	for (vector<pair<double,double>>::size_type i = 0; i < num_points; i++)
	{
		TSP::TspSolution* solution = TSPSolver::JitGreedy(i);
		if (opt->distance == 0 || opt->distance > solution->distance)
		{
			delete opt;
			opt = solution;
		}
	}
	return opt;
}

TSP::TspSolution* TSPSolver::Opt2(TSP::TspSolution* starting, long iterations)
{
	if (!sortedDistanceMatrix)
	{
		InitDistanceMatrix();
	}

	return starting;
}

	void TSPSolver::InitDistanceMatrix()
	{
	distanceMatrix = new vector<vector<double> >(num_points, vector<double>(num_points));
	BuildDistanceMatrix(points, *distanceMatrix);

	sortedDistanceMatrix = new vector<vector<pair<long,double> > >(num_points, vector<pair<long,double>>(num_points));
	SortDistanceMatrix(*distanceMatrix, *sortedDistanceMatrix);
	}
