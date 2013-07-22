#include "Util.h"
#include <algorithm>
#include <iostream>
using namespace std;

double CalcDistance(const _tpoint& p1, const _tpoint& p2)
{
	if (p1 == p2)
		return 0;
	return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}

void PrintMatrix(const vector<vector<double> >& matrix)
{
	for (vector<vector<double> >::const_iterator it1 = matrix.begin(); it1 != matrix.end(); it1++)
	{
		for (vector<double>::const_iterator it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << " "; 
		}
		cout << endl;
	}
}
void PrintPointsVector(_tpoints points)
{
	for (_tpoints::iterator it = points.begin(); it != points.end(); it++)
	{
		std::cout << it->first << " " << it->second << '\n'; 
	}
}
void BuildDistanceMatrix(const _tpoints& points, vector<vector<double> >& matrix)
{

	vector<vector<double> >::iterator row = matrix.begin();
	for (_tpoints::const_iterator it1 = points.begin(); it1 != points.end(); it1++)
	{
		vector<double>::iterator col = row->begin();
		for (_tpoints::const_iterator it2 = points.begin(); it2 != points.end(); it2++)
		{
			if (it1 == it2)
				*col = 0;
			else
				*col = CalcDistance(*it1,*it2);
			col++;
		}
		row++;
	}
}
void SortDistanceMatrix(const vector<vector<double> >& matrix, vector<vector<pair<long,double> > >& sorted_matrix)
{
	vector<vector<pair<long,double> > >::iterator row = sorted_matrix.begin();
	for (vector<vector<double> >::const_iterator it1 = matrix.begin(); it1 != matrix.end(); it1++)
	{
		long colnum = 0;
		vector<pair<long,double> >::iterator col = row->begin();
		for (vector<double>::const_iterator it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			*col = make_pair(colnum,*it2);
			col++;
			colnum++;
		}
		sort(row->begin(),row->end(),CmpDist);
		row++;
	}
}
void PrintPointMatrix (const vector<vector<pair<long,double> > >& matrix)
{
	for (vector<vector<pair<long,double>> >::const_iterator it1 = matrix.begin(); it1 != matrix.end(); it1++)
	{
		for (vector<pair<long,double>>::const_iterator it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << "(" << it2->first <<" , "  << it2->second << ") "; 
		}
		cout << endl;
	}
}

bool CmpDist(const pair<long,double>& p1,const  pair<long,double>& p2) 
{
	return p1.second < p2.second;
}

void DeletePointFromSortedmatrix(long point, vector<vector<pair<long,double> > >& matrix)
{
	Finder finder(point);
	for (vector<vector<pair<long,double>> >::iterator it1 = matrix.begin(); it1 != matrix.end(); it1++)
	{
		vector<pair<long,double>>::const_iterator it = find_if(it1->begin(),it1->end(),finder);
		if (it != it1->end())
			it1->erase(it);
	}
}

void BuildDistanceVector(long point, const _tpoints& points, vector<double>& vec)
{
	vector<double>::iterator vecit = vec.begin();
	for (_tpoints::const_iterator it = points.begin(); it != points.end(); it++, vecit++)
	{
		*vecit = CalcDistance(points[point],*it);
	}
}

void SortDistanceVector(const vector<double>& vec, vector<pair<long,double> >& sorted_vector)
{
	vector<pair<long,double> >::iterator itvec = sorted_vector.begin();
	long n = 0;
	for (vector<double>::const_iterator it1 = vec.begin(); it1 != vec.end(); it1++, itvec++, n++)
	{
		*itvec = make_pair(n,*it1);

	}
	sort(sorted_vector.begin(),sorted_vector.end(),CmpDist);
}