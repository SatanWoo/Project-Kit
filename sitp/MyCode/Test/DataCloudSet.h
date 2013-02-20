#ifndef _DATACLOUDSET_H
#define _DATACLOUDSET_H
using namespace std;
#include "vertex.h"
#include <vector>
#include <iostream>

class DataCloudSet
{
public:
	DataCloudSet();
	void addVertex(Vertex *vertex);
	void print();
	Vertex *getVertexAt(int i);
	int getCount()const {return vetex.size();}
	Vertex **subSet(int start, int count);
	Vertex **subSetWithBiggerXAndSmallerY(float x , float y, int &total);
	Vertex **subSetWithBiggerXAndBiggerY(float x,float y, int &total);
	Vertex **subsetWithSmallerXAndSmallerY(float x ,float y, int &total);
	Vertex **subSetWithSmallerXAndBiggerY(float x, float y, int &total);
protected:
	vector<Vertex *>vetex;
};

#endif