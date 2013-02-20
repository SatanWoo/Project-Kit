#include "DataCloudSet.h"


void DataCloudSet::addVertex(Vertex *vertex)
{
	vetex.push_back(vertex);
}

DataCloudSet::DataCloudSet()
{

}

void DataCloudSet::print()
{
	cout << "Count of vector is " << vetex.size() << endl;
}

Vertex *DataCloudSet::getVertexAt(int i)
{
	if (i < 0 || i >= vetex.size())
		return NULL;
	return vetex[i];
}

Vertex **DataCloudSet::subSet(int start, int count)
{
	if (start < 0 || (start + count) >= vetex.size()) return NULL;
	Vertex **subset = new Vertex *[count];
	for (int i = start; i < count;i ++)
	{
		subset[i] = new Vertex();
		subset[i] = vetex[i];
	}
	return subset;
}

Vertex **DataCloudSet::subSetWithBiggerXAndBiggerY(float x,float y, int &total)
{
	total = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() > x && vetex[i]->getY() > y )
		{
			total ++;
		}
	}

	Vertex **subset = new Vertex *[total];
	int index = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() > x && vetex[i]->getY() > y )
		{
			subset[index++] = vetex[i];
		}
	}

	return subset;
}

Vertex **DataCloudSet::subsetWithSmallerXAndSmallerY(float x,float y, int &total)
{
	total = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() < x && vetex[i]->getY() < y )
		{
			total ++;
		}
	}

	Vertex **subset = new Vertex *[total];
	int index = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() < x && vetex[i]->getY() < y )
		{
			subset[index++] = vetex[i];
		}
	}

	return subset;
}

Vertex **DataCloudSet::subSetWithSmallerXAndBiggerY(float x, float y, int &total)
{
	total = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() < x && vetex[i]->getY() > y )
		{
			total ++;
		}
	}

	Vertex **subset = new Vertex *[total];
	int index = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() < x && vetex[i]->getY() > y )
		{
			subset[index++] = vetex[i];
		}
	}

	return subset;
}

Vertex **DataCloudSet::subSetWithBiggerXAndSmallerY(float x , float y, int &total)
{
	total = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() > x && vetex[i]->getY() < y )
		{
			total ++;
		}
	}

	Vertex **subset = new Vertex *[total];
	int index = 0;
	for (int i = 0; i < vetex.size(); i++)
	{
		if (vetex[i]->getX() > x && vetex[i]->getY() < y )
		{
			subset[index++] = vetex[i];
		}
	}

	return subset;
}


