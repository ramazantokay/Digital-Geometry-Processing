#define _CRT_SECURE_NO_DEPRECATE
#include <inttypes.h>
#define HAVE_INT8_T
#include <cmath>
#include <xlocnum>

#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoIndexedFaceSet.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoShapeHints.h>
#include <Inventor/nodes/SoDrawStyle.h>
#include <Inventor/nodes/SoIndexedLineSet.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoSphere.h>
#include "Mesh.h"


class Painter
{
public:
	SoSeparator* getShapeSep(Mesh* mesh);
	SoSeparator* drawEdge(Mesh* mesh, int edgeIndex);
	SoSeparator* paintCurvature(Mesh* mesh, vector<int>& vertsToColored);
	SoSeparator* paintSphere(Mesh* mesh, vector<int>& vertsToSpehered);
};
