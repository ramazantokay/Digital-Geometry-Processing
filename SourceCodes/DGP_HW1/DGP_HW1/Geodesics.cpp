#include "Geodesics.h"

Geodesics::Geodesics(Mesh* mesh)
{
	this->mesh = mesh;
}

void Geodesics::dijkstraArrayImplementation(int startVertex, vector<float>& distance, vector<int>& prev)
{
	int sizeN = this->mesh->verts.size();

	vector<bool> isVisited(sizeN, false); // at the begining all elements are considered as unvisited
	distance[startVertex] = 0.0;

	for (int i = 0; i < sizeN; i++)
	{
		int minIndex = minDistanceDijkstraArrayHelper(distance, isVisited, sizeN);
		isVisited[minIndex] = true;

		for (auto adjVert : this->mesh->verts[minIndex]->vertList) // adj vert list
		{
			float distBetweenAdjVert = distance[minIndex] + this->mesh->calcDistanceOfAdjVert(minIndex, adjVert);
			if (!isVisited[adjVert] && distBetweenAdjVert < distance[adjVert])
			{
				distance[adjVert] = distBetweenAdjVert;
				prev[adjVert] = minIndex;
			}
		}
	}
}

void Geodesics::dijkstraMinHeapImplemenation(int startVertex, vector<float>& distance, vector<int>& prev)
{
	int vertSize = this->mesh->verts.size();
	priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> priortiyQueue;

	vector<bool> isVisited(vertSize, false);

	priortiyQueue.push(make_pair(0.0, startVertex));
	distance[startVertex] = 0.0;

	while (!priortiyQueue.empty())
	{
		int currVertex = priortiyQueue.top().second;
		priortiyQueue.pop();
		isVisited[currVertex] = true;

		for (auto adjVert : this->mesh->verts[currVertex]->vertList)
		{
			float distBetweenAdjVert = distance[currVertex] + this->mesh->calcDistanceOfAdjVert(currVertex, adjVert);
			if (!isVisited[adjVert] && distBetweenAdjVert < distance[adjVert])
			{
				distance[adjVert] = distBetweenAdjVert;
				priortiyQueue.push(make_pair(distance[adjVert], adjVert));
				prev[adjVert] = currVertex;
			}

		}
	}
}

void Geodesics::dijkstraFibHeapImplemenation(int startVertex, vector<float>& distance, vector<int>& prev)
{
	int vertSize = this->mesh->verts.size();
	vector<bool> isVisited(vertSize, false);

	FibonacciHeap<pair<float, int>> fibonacciHeap;
	fibonacciHeap.insert(make_pair(0.0, startVertex));

	distance[startVertex] = 0.0;

	while (!fibonacciHeap.isEmpty())
	{
		int currVertex = fibonacciHeap.getMinimum().second;
		fibonacciHeap.removeMinimum();
		isVisited[currVertex] = true;

		for (auto adjVert : this->mesh->verts[currVertex]->vertList)
		{
			float distBetweenAdjVert = distance[currVertex] + this->mesh->calcDistanceOfAdjVert(currVertex, adjVert);
			if (!isVisited[adjVert] && distBetweenAdjVert < distance[adjVert])
			{
				distance[adjVert] = distBetweenAdjVert;
				fibonacciHeap.insert(make_pair(distance[adjVert], adjVert));
				prev[adjVert] = currVertex;
			}
		}
	}
}

int Geodesics::minDistanceDijkstraArrayHelper(vector<float> distance, vector<bool> isVisited, int sizeN)
{
	float min = INFINITY;
	int minIndex;

	for (int i = 0; i < sizeN; i++)
		if (isVisited[i] == false && distance[i] <= min)
			min = distance[i], minIndex = i;

	return minIndex;
}

void Geodesics::pathReconstruction(int start, int target, vector<int> prev, vector<int>& edgesPath, vector<int>& vertsPath)
{
	int currVert = target;
	vertsPath.push_back(currVert);

	while (currVert != start)
	{
		int preVert = prev[currVert];
		vertsPath.push_back(preVert);

		int edgeId = this->mesh->getEdgeId(preVert, currVert);
		edgesPath.push_back(edgeId);
		currVert = preVert;
	}
}

void Geodesics::writeMatrixToFile(vector<int>& prev, string& fileName)
{
	// Writing to a file
	int sizeN = this->mesh->verts.size();

	vector<vector<float>> M(sizeN);

	for (size_t i = 0; i < sizeN; i++)
	{
		M[i] = vector<float>(sizeN, numeric_limits<float>::infinity());
		dijkstraFibHeapImplemenation(0, M[i], prev);
		//cerr << "step " << i << endl;
	}
	ofstream file;
	file.open(fileName.c_str());

	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < sizeN - 1; j++)
		{
			file << M[i][j] << " ";
		}
		file << M[i][sizeN - 1] << "\n";
	}
	file.close();
}
