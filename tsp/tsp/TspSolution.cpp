#include "TspSolution.h"
#include "Util.h"
#include <iostream>

namespace TSP
{
	TspSolution::TspSolution(long point)
		: distance(0.0)
	{
		tour.push_back(point);
	}
	TspSolution::TspSolution(const TspSolution& solution)
		: distance(solution.distance), tour(solution.tour)
	{
	}



	TspSolution::~TspSolution(void)
	{
	}

	void TspSolution::Print()
	{
		std::cout << distance << " " << 0 << std::endl;
		for (vector<long>::iterator it = tour.begin(); it != tour.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	void TspSolution::AddPoint(long point, double dist)
	{
		distance += dist;
		tour.push_back(point);
	}

	
	void TspSolution::MakeCycle(const vector<vector<double> >& matrix)
	{
		distance += matrix[tour.front()][tour.back()];
	}
	
	void TspSolution::MakeCycle(const vector<pair<double,double> >& points)
	{
		distance += CalcDistance(points[tour.front()], points[tour.back()]);
	}



}