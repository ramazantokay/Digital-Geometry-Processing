#pragma once
#include <fstream>
#include <iostream>
#include <queue>
#include "FibonacciHeap.h"
#include "Mesh.h"

using namespace std;

// Geodesics distance algorithm implementations

class Geodesics
{
public:
	Geodesics(Mesh* mesh);
	void dijkstraArrayImplementation(int startVertex, vector<float>& distance, vector<int>& prev);
	void dijkstraMinHeapImplemenation(int startVertex, vector<float>& distance, vector<int>& prev);
	void dijkstraFibHeapImplemenation(int startVertex, vector<float>& distance, vector<int>& prev);
	
	// helper function for geodesics
public:
	int minDistanceDijkstraArrayHelper(vector<float> distance, vector<bool> isVisited, int sizeN);
	//  creates the geodesic path
	void pathReconstruction(int start, int target, vector<int> prev, vector<int>& edgesPath, vector<int>& vertsPath);
	// writes the NxN matrix to a file
	void writeMatrixToFile(vector<int>& prev, string& fileName);
private:
	Mesh* mesh;
};