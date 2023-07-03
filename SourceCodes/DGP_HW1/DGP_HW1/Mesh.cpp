#define _CRT_SECURE_NO_DEPRECATE

#include "Mesh.h"


void Mesh::loadOff(char* name)
{
	FILE* fPtr = fopen(name, "r");
	char str[334];

	fscanf(fPtr, "%s", str);

	int nVerts, nTris, n, i = 0;
	float x, y, z;

	fscanf(fPtr, "%d %d %d\n", &nVerts, &nTris, &n);
	while (i++ < nVerts)
	{
		fscanf(fPtr, "%f %f %f", &x, &y, &z);
		addVertex(x, y, z);
	}

	while (fscanf(fPtr, "%d", &i) != EOF)
	{
		fscanf(fPtr, "%f %f %f", &x, &y, &z);
		addTriangle((int)x, (int)y, (int)z);
	}

	fclose(fPtr);
}

float Mesh::calcDistanceOfAdjVert(int vertex1, int vertex2)
{
	return sqrt(pow((verts[vertex2]->coords[0] - verts[vertex1]->coords[0]), 2) +
		pow((verts[vertex2]->coords[1] - verts[vertex1]->coords[1]), 2) +
		pow((verts[vertex2]->coords[2] - verts[vertex1]->coords[2]), 2) * 1.0
	);
}


void Mesh::createCube(float sideLen)
{
	//coordinates
	float flbc[3] = { 0, 0, 0 }, deltaX = 0, deltaY = 0, deltaZ = 0;
	for (int v = 0; v < 8; v++)
	{
		switch (v)
		{
		case 1:
			deltaX = sideLen;
			break;
		case 2:
			deltaZ = -sideLen;
			break;
		case 3:
			deltaX = 0;
			break;
		case 4:
			deltaZ = 0;
			deltaY = sideLen;
			break;
		case 5:
			deltaX = sideLen;
			break;
		case 6:
			deltaZ = -sideLen;
			break;
		default:
			deltaX = 0;;
			break;
		}
		addVertex(flbc[0] + deltaX, flbc[1] + deltaY, flbc[2] + deltaZ);
	}

	addTriangle(0, 2, 1);
	addTriangle(0, 3, 2);

	addTriangle(1, 2, 5);
	addTriangle(2, 6, 5);

	addTriangle(2, 3, 6);
	addTriangle(3, 7, 6);

	addTriangle(3, 4, 7);
	addTriangle(3, 0, 4);

	addTriangle(4, 5, 6);
	addTriangle(4, 6, 7);

	addTriangle(0, 1, 5);
	addTriangle(0, 5, 4);
}

void Mesh::addTriangle(int v1, int v2, int v3)
{
	int idx = tris.size();
	tris.push_back(new Triangle(idx, v1, v2, v3));

	//set up structure

	verts[v1]->triList.push_back(idx);
	verts[v2]->triList.push_back(idx);
	verts[v3]->triList.push_back(idx);

	if (!makeVertsNeighbor(v1, v2))
		addEdge(v1, v2);

	if (!makeVertsNeighbor(v1, v3))
		addEdge(v1, v3);

	if (!makeVertsNeighbor(v2, v3))
		addEdge(v2, v3);

}

bool Mesh::makeVertsNeighbor(int v1i, int v2i)
{
	//returns true if v1i already neighbor w/ v2i; false o/w

	for (int i = 0; i < verts[v1i]->vertList.size(); i++)
		if (verts[v1i]->vertList[i] == v2i)
			return true;


	verts[v1i]->vertList.push_back(v2i);
	verts[v2i]->vertList.push_back(v1i);
	return false;
}

void Mesh::addVertex(float x, float y, float z)
{
	int idx = verts.size();
	float* c = new float[3];
	c[0] = x;
	c[1] = y;
	c[2] = z;

	verts.push_back(new Vertex(idx, c));
}

void Mesh::addEdge(int v1, int v2)
{
	int idx = edges.size();

	edges.push_back(new Edge(idx, v1, v2));

	verts[v1]->edgeList.push_back(idx);
	verts[v2]->edgeList.push_back(idx);
}


int Mesh::getEdgeId(int src, int dest) {
	if (find(verts[src]->vertList.begin(), verts[src]->vertList.end(), dest) != verts[src]->vertList.end()) {
		vector<int> v(1);
		vector<int>::iterator it;

		it = std::set_intersection(verts[src]->edgeList.begin(), verts[src]->edgeList.end(), verts[dest]->edgeList.begin(), verts[dest]->edgeList.end(), v.begin());

		if (v.size() == 1)
		{
			int edge_index = *(v.begin());
			return edge_index;
		}
	}
	else {
		cout << "(0 _ 0)" << endl;
		return -1;
	}
}
