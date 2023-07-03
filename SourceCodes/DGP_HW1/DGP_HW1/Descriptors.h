#pragma once
#include "Geodesics.h"

// Gaussian curvature and average geodesic distance implementations

class Descriptors
{
public:
	Descriptors(Geodesics* geo, Mesh* mesh);
	//  Gaussian Curvature implementation
	void gaussianCurvature(vector<float>& kG);
	void generateGaussianCurvature(vector<int>& colorVerts);
	// FPS implementation
	void farthestSamplingPoints(vector<int>& fpsPoints);
	// AVG implementation
	void averageGeodesicDistance(vector<float>& avgDistance);
	void generateAverageGeodesicDistance(vector<int>& colorVerts);
	// laplacian smoothing
	void laplacianSmoothing(vector<SbVec3f>& displacement);
	
public:
	// helper functions
	float findAngleBetweenAdjVerts(Vertex* vert, int index);

private:
	Geodesics* geo;
	Mesh* mesh;
};