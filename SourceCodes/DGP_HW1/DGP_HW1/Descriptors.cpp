#include "Descriptors.h"

Descriptors::Descriptors(Geodesics* geo, Mesh* mesh)
{
	this->geo = geo;
	this->mesh = mesh;
}

void Descriptors::gaussianCurvature(vector<float>& kG)
{
	for (auto vert : this->mesh->verts)
	{
		float defectAngle = 2 * M_PI; //2PI

		for (auto adj : vert->triList)
		{
			float adjAngle = findAngleBetweenAdjVerts(vert, adj);
			defectAngle -= adjAngle;
		}
		kG.push_back(defectAngle);
	}
}

void Descriptors::generateGaussianCurvature(vector<int>& colorVerts)
{
	vector<float> kG;
	gaussianCurvature(kG);

	for (int i = 0; i < kG.size(); i++)
	{
		//if (kG[i] >= 0.0f && kG[i] <= 0.001f) //  spherical or elliptic   k=0
		if (kG[i] == 0.0f) //  spherical or elliptic   if kG=0 color green
			colorVerts[i] = 1;
		else if (kG[i] > 0.0f) // cylindrical or parabolic if kG > 0 color blue
			colorVerts[i] = 2;
		else //addle-shaped or hyperbolic if kG<0  color red
			colorVerts[i] = 0;
	}
}

void Descriptors::farthestSamplingPoints(vector<int>& fpsPoints)
{
	int vertSize = this->mesh->verts.size();

	fpsPoints.push_back(0); // starting point

	vector<float> distance(vertSize, numeric_limits<float>::infinity());
	vector<int> prev(vertSize);

	geo->dijkstraFibHeapImplemenation(0, distance, prev);

	int fp = std::distance(distance.begin(), std::max_element(distance.begin(), distance.end()));
	fpsPoints.push_back(fp);

	for (int i = 0; i < 100; i++)
	{
		vector<float> distance2(vertSize, numeric_limits<float>::infinity());
		vector<int> prev2(vertSize);

		geo->dijkstraFibHeapImplemenation(fp, distance2, prev2);

		for (int j = 0; j < distance.size(); j++)
		{
			if (distance2[j] < distance[j])
				distance[j] = distance2[j];
		}
		fp = std::distance(distance.begin(), std::max_element(distance.begin(), distance.end()));
		fpsPoints.push_back(fp);
	}
}

void Descriptors::averageGeodesicDistance(vector<float>& avgDistance)
{
	int vertSize = this->mesh->verts.size();
	vector<int> fpsPoints;
	farthestSamplingPoints(fpsPoints);
	vector<vector<float>> sumOfDistance;

	for (int i = 0; i < 100; i++)
	{
		vector<float> distance(vertSize, numeric_limits<float>::infinity());
		vector<int> prev(vertSize);

		geo->dijkstraFibHeapImplemenation(fpsPoints[i], distance, prev);
		sumOfDistance.push_back(distance);
	}

	for (int i = 0; i < vertSize; i++)
	{
		float sum = 0.0f;
		for (int j = 0; j < 100; j++)
			sum += sumOfDistance[j][i];
		avgDistance.push_back(sum);
	}

}

void Descriptors::generateAverageGeodesicDistance(vector<int>& colorVerts)
{
	// I couldn't figure out how should i create the color histogram, this is my color histogram (0 _ 0)

	vector<float> avg;
	float diffF;
	averageGeodesicDistance(avg);

	float minAVG = *min_element(avg.begin(), avg.end());
	float maxAVG = *max_element(avg.begin(), avg.end());

	diffF = maxAVG - minAVG;

	for (int i = 0; i < avg.size(); i++)
	{
		if (avg[i] < diffF)
			colorVerts[i] = 1;
		else if (avg[i] > diffF)
			colorVerts[i] = 2;
		else
			colorVerts[i] = 0;
	}
}

void Descriptors::laplacianSmoothing(vector<SbVec3f>& displacement)
{
	int sizeN = this->mesh->verts.size();

	for (auto vert : this->mesh->verts)
	{
		float totalX = 0.0f;
		float totalY = 0.0f;
		float totalZ = 0.0f;

		//cout << *vert->coords << " " << *(vert->coords + 1) << " " << *(vert->coords + 2) << endl;
		for (auto neigh : vert->vertList)
		{
			totalX += *(this->mesh->verts[neigh]->coords);
			totalY += *(this->mesh->verts[neigh]->coords + 1);
			totalZ += *(this->mesh->verts[neigh]->coords + 2);
		}

		// displacement vector
		displacement[vert->idx].setValue(*(vert->coords) - (totalX / vert->vertList.size()),
			*(vert->coords + 1) - (totalY / vert->vertList.size()),
			*(vert->coords + 2) - (totalZ / vert->vertList.size()));


		*(vert->coords) = totalX / vert->vertList.size();
		*(vert->coords + 1) = totalY / vert->vertList.size();
		*(vert->coords + 2) = totalZ / vert->vertList.size();

	}
}

float Descriptors::findAngleBetweenAdjVerts(Vertex* vert, int index)
{
	Triangle* triangle = this->mesh->tris[index];
	int v1 = triangle->v1i;
	int v2 = triangle->v2i;
	int v3 = triangle->v3i;

	Vertex* vertex1 = this->mesh->verts[v1];
	Vertex* vertex2 = this->mesh->verts[v2];
	Vertex* vertex3 = this->mesh->verts[v3];

	SbVec3f vec1, vec2;

	float thetaAngle = 0.0f, vec1Len, vec2Len, dot;

	if (vert->idx == v1)
	{
		vec1Len = this->mesh->calcDistanceOfAdjVert(v1, v2);
		vec2Len = this->mesh->calcDistanceOfAdjVert(v1, v3);

		vec1.setValue((vertex2->coords[0] - vertex1->coords[0]),
			(vertex2->coords[1] - vertex1->coords[1]),
			(vertex2->coords[2] - vertex1->coords[2]));

		vec2.setValue((vertex3->coords[0] - vertex1->coords[0]),
			(vertex3->coords[1] - vertex1->coords[1]),
			(vertex3->coords[2] - vertex1->coords[2]));

		dot = vec1.dot(vec2);

		thetaAngle = acos(dot / (vec1Len * vec2Len));

	}
	else if (vert->idx == v2)
	{
		vec1Len = this->mesh->calcDistanceOfAdjVert(v2, v1);
		vec2Len = this->mesh->calcDistanceOfAdjVert(v2, v3);

		vec1.setValue((vertex1->coords[0] - vertex2->coords[0]),
			(vertex1->coords[1] - vertex2->coords[1]),
			(vertex1->coords[2] - vertex2->coords[2]));

		vec2.setValue((vertex3->coords[0] - vertex2->coords[0]),
			(vertex3->coords[1] - vertex2->coords[1]),
			(vertex3->coords[2] - vertex2->coords[2]));

		dot = vec1.dot(vec2);

		thetaAngle = acos(dot / (vec1Len * vec2Len));
	}
	else if (vert->idx == v3)
	{
		vec1Len = this->mesh->calcDistanceOfAdjVert(v3, v2);
		vec2Len = this->mesh->calcDistanceOfAdjVert(v3, v1);

		vec1.setValue((vertex2->coords[0] - vertex3->coords[0]),
			(vertex2->coords[1] - vertex3->coords[1]),
			(vertex2->coords[2] - vertex3->coords[2]));

		vec2.setValue((vertex1->coords[0] - vertex3->coords[0]),
			(vertex1->coords[1] - vertex3->coords[1]),
			(vertex1->coords[2] - vertex3->coords[2]));

		dot = vec1.dot(vec2);

		thetaAngle = acos(dot / (vec1Len * vec2Len));
	}

	return thetaAngle;
}


