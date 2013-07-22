#pragma once

#include <vector>

using namespace std;

typedef std::pair<double,double> _tpoint;
typedef std::vector<_tpoint> _tpoints;

class Finder
{
public:
	Finder(long i)
		:point(i)
	{

	}
	bool operator() (const pair<long,double>& pr)
	{
		return (pr.first == point);
	}

private:
	long point;

};

double CalcDistance(const _tpoint& p1, const _tpoint& p2);
void PrintMatrix(const vector<vector<double> >& matrix);
void PrintPointsVector(_tpoints points);
void BuildDistanceMatrix(const _tpoints& points, vector<vector<double> >& matrix);
void SortDistanceMatrix(const vector<vector<double> >& matrix, vector<vector<pair<long,double> > >& sorted_matrix);
void PrintPointMatrix (const vector<vector<pair<long,double> > >& matrix);
bool CmpDist(const pair<long,double>& p1,const  pair<long,double>& p2);
void DeletePointFromSortedmatrix(long point, vector<vector<pair<long,double> > >& matrix);

void BuildDistanceVector(long point, const _tpoints& points,vector<double>& vec);
void SortDistanceVector(const vector<double>& vec, vector<pair<long,double> >& sorted_vector);