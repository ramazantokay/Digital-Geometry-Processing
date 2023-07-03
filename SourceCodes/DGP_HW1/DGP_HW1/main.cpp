#define _CRT_SECURE_NO_DEPRECATE
#include <inttypes.h>
#define HAVE_INT8_T
#include <cmath>
#include <xlocnum>

#include <chrono>
#include <fstream>
#include <iostream>
#include <Inventor/Win/SoWin.h>
#include <Inventor/Win/viewers/SoWinExaminerViewer.h>

#include "Mesh.h"
#include "Painter.h"
#include "Geodesics.h"
#include "Descriptors.h"

int main(int, char** argv)
{
	HWND window = SoWin::init(argv[0]);

	SoWinExaminerViewer* viewer = new SoWinExaminerViewer(window);

	//make a dead simple scene graph by using the Coin library, only containing a single cone under the scenegraph root
	SoSeparator* root = new SoSeparator;
	root->ref();

	Mesh* mesh = new Mesh();
	Painter* painter = new Painter();

	Geodesics geo(mesh);
	Descriptors descriptor(&geo, mesh);
	int query;

	cout << "DGP HW1 - Ramazan TOKAY " << endl;
	cout << endl;
	cout << "1: Dijkstra Array Implementation" << endl;
	cout << "2: Dijkstra Min Heap Implementation" << endl;
	cout << "3: Dijkstra Fibonnacci Heap Implementation" << endl;
	cout << "4: Write NxN geodesic distance matrix to a file" << endl;
	cout << "5: Gaussian Curvature Descriptor" << endl;
	cout << "6: Average Geodesic Distances Descriptor" << endl;
	cout << "7: Laplacian Smoothing " << endl;
	cout << "Enter the id for the desired task:" << endl;
	cin >> query;


	mesh->loadOff((char*)"0.off");
	//mesh->loadOff((char*)"sphere.off");
	//mesh->loadOff((char*)"torus.off");
	//mesh->loadOff((char*)"bunny.off");
	//mesh->loadOff((char*)"beetle.off");
	//mesh->loadOff((char*)"gorilla.off");
	//mesh->loadOff((char*)"cat.off");
	//mesh->createCube(20.0f);

	if (query == 1)
	{
		int sizeN = mesh->verts.size();
		int startV, endV;
		cout << "1: Dijkstra Array Implementation" << endl;
		cout << "Please, firstly, enter start vertex, and then enter end vertex. The selectable range is [0, " << sizeN << "] for this selected mesh." << endl;
		cin >> startV;
		cin >> endV;

		if (startV<0 || startV>endV)
		{
			cout << "Please enter the start vertex in the range" << " --> the range is[0, " << sizeN << "]"<< endl;
			exit(1);
		}


		if (endV > sizeN)
		{
			cout << "Please enter the end vertex in the range" << " --> the range is[0, " << sizeN << "]"<< endl;
			exit(1);
		}

		vector<float> distance(sizeN, numeric_limits<float>::infinity());
		vector<int> prevArray(sizeN);

		// Time for Array Dijkstra
		std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
		geo.dijkstraArrayImplementation(startV, distance, prevArray);
		std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeDiff = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
		cout << "dijkstraArrayImplementation Time " << timeDiff.count() << endl;

		vector<int> edge, vert;
		geo.pathReconstruction(startV, endV, prevArray, edge, vert);

		cout << "Total # Vertices: " << mesh->verts.size() << endl;
		cout << "Path edges: " << endl;
		// Print Edges
		for (size_t i = 0; i < edge.size(); i++)
		{
			cout << edge[i] << endl;
			root->addChild(painter->drawEdge(mesh, edge[i]));
		}
		root->addChild(painter->getShapeSep(mesh)); // shape rendering
	}
	if (query == 2)
	{
		int sizeN = mesh->verts.size();
		int startV, endV;
		cout << "2: Dijkstra Min Heap Implementation" << endl;
		cout << "Please, firstly, enter start vertex, and then enter end vertex. The selectable range is [0, " << sizeN << "] for this selected mesh." << endl;
		cin >> startV;
		cin >> endV;

		if (startV<0 || startV>endV)
		{
			cout << "Please enter the start vertex in the range" << " --> the range is[0, " << sizeN << "]" << endl;
			exit(1);
		}


		if (endV > sizeN)
		{
			cout << "Please enter the end vertex in the range" << " --> the range is[0, " << sizeN << "]"<<  endl;
			exit(1);
		}

		vector<float> distance(sizeN, numeric_limits<float>::infinity());
		vector<int> prevArray(sizeN);

		// Time for Min Heap Dijkstra

		std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
		geo.dijkstraMinHeapImplemenation(startV, distance, prevArray);
		std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeDiff = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
		cout << "dijkstraMinHeapImplementation Time " << timeDiff.count() << endl;

		vector<int> edge, vert;
		geo.pathReconstruction(startV, endV, prevArray, edge, vert);

		cout << "Total # Vertices: " << mesh->verts.size() << endl;
		cout << "Path edges: " << endl;
		// Print Edges
		for (size_t i = 0; i < edge.size(); i++)
		{
			cout << edge[i] << endl;
			root->addChild(painter->drawEdge(mesh, edge[i]));
		}
		root->addChild(painter->getShapeSep(mesh)); // shape rendering

	}
	if (query == 3)
	{
		int sizeN = mesh->verts.size();
		int startV, endV;
		cout << "3: Dijkstra Fibonnacci Heap Implementation" << endl;
		cout << "Please, firstly enter start vertex, and then enter end vertex. The selectable range is [0, " << sizeN << "] for this selected mesh." << endl;
		cin >> startV;
		cin >> endV;

		if (startV<0 || startV>endV)
		{
			cout << "Please enter the start vertex in the range" << " --> the range is[0, " << sizeN << "]" << endl;
			exit(1);
		}


		if (endV > sizeN)
		{
			cout << "Please enter the end vertex in the range" << " --> the range is[0, " << sizeN << "]" << endl;
			exit(1);
		}


		vector<float> distance(sizeN, numeric_limits<float>::infinity());
		vector<int> prevArray(sizeN);

		// Time for Fib Heap Dijkstra
		std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
		geo.dijkstraFibHeapImplemenation(startV, distance, prevArray);
		std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> timeDiff = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
		cout << "dijkstraFibHeapImplementation Time " << timeDiff.count() << endl;

		vector<int> edge, vert;
		geo.pathReconstruction(startV, endV, prevArray, edge, vert);

		cout << "Total # Vertices: " << mesh->verts.size() << endl;
		cout << "Path edges: " << endl;
		// Print Edges
		for (size_t i = 0; i < edge.size(); i++)
		{
			cout << edge[i] << endl;
			root->addChild(painter->drawEdge(mesh, edge[i]));
		}
		root->addChild(painter->getShapeSep(mesh)); // shape rendering
	}
	else if (query == 4)
	{
		cout << "4: Write NxN geodesic distance matrix to a file" << endl;

		int sizeN = mesh->verts.size();
		vector<float> distance(sizeN, numeric_limits<float>::infinity());
		vector<int> prevArray(sizeN);

		// Writing to a file
		string fileName = "Matrix File for gorilla.txt";
		geo.writeMatrixToFile(prevArray, fileName);
		root->addChild(painter->getShapeSep(mesh)); // shape rendering

		cout << "END" << endl;

	}
	else if (query == 5)
	{
		cout << "5: Gaussian Curvature Descriptor" << endl;

		vector<int> tempCurv(mesh->verts.size(), 0);
		descriptor.generateGaussianCurvature(tempCurv);
		root->addChild(painter->paintCurvature(mesh, tempCurv));
	}
	else if (query == 6)
	{
		cout << "6: Average Geodesic Distances Descriptor" << endl;

		vector<int> avgTemp(mesh->verts.size(), 0);
		descriptor.generateAverageGeodesicDistance(avgTemp);
		root->addChild(painter->paintCurvature(mesh, avgTemp));
	}
	else if (query == 7)
	{
		vector<SbVec3f> displacementVector(mesh->verts.size());

		for (int i = 0; i < 20; i++)
		{
			descriptor.laplacianSmoothing(displacementVector);
		}

		// debug print
		/*cout << "Displacement Vector" << endl; 
		for (int i = 0; i < displacementVector.size(); i++)
		{
			cout << *(displacementVector[i].getValue()) << " " << *(displacementVector[i].getValue() + 1) << " " << *(displacementVector[i].getValue() + 2) << endl;
		}*/


		vector<int> avgTemp(mesh->verts.size(), 0);
		descriptor.generateAverageGeodesicDistance(avgTemp);
		root->addChild(painter->paintCurvature(mesh, avgTemp));
		//root->addChild(painter->getShapeSep(mesh)); // shape rendering
	}

	viewer->setSize(SbVec2s(1280, 720));
	viewer->setSceneGraph(root);
	viewer->show();

	SoWin::show(window);
	SoWin::mainLoop();
	delete viewer;
	root->unref();
	return 0;
}
