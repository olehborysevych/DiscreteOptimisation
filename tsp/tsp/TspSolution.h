#pragma once
#include <vector>

using namespace std;

namespace TSP
{
	class TspSolution
	{
	public:
		vector<long> tour;
		double distance;

		TspSolution(long point);
		TspSolution(const TspSolution& solution);

		~TspSolution(void);
		
		void AddPoint(long point, double dist);
		void MakeCycle(const vector<vector<double> >& matrix);
		void MakeCycle(const vector<pair<double,double> >& points);
		void Print(void);
	};
}

