#ifndef COIN_SOSHAPEHINTS_H
#define COIN_SOSHAPEHINTS_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

#include <Inventor/elements/SoShapeHintsElement.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/nodes/SoSubNode.h>

class COIN_DLL_API SoShapeHints : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoShapeHints);

public:
  static void initClass(void);
  SoShapeHints(void);

  enum VertexOrdering {
    UNKNOWN_ORDERING = SoShapeHintsElement::UNKNOWN_ORDERING,
    CLOCKWISE = SoShapeHintsElement::CLOCKWISE,
    COUNTERCLOCKWISE = SoShapeHintsElement::COUNTERCLOCKWISE
  };

  enum ShapeType {
    UNKNOWN_SHAPE_TYPE = SoShapeHintsElement::UNKNOWN_SHAPE_TYPE,
    SOLID = SoShapeHintsElement::SOLID
  };

  enum FaceType {
    UNKNOWN_FACE_TYPE = SoShapeHintsElement::UNKNOWN_FACE_TYPE,
    CONVEX = SoShapeHintsElement::CONVEX
  };

  SoSFEnum vertexOrdering;
  SoSFEnum shapeType;
  SoSFEnum faceType;
  SoSFFloat creaseAngle;

  virtual void doAction(SoAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void pick(SoPickAction * action);

protected:
  virtual ~SoShapeHints();
};

#endif // !COIN_SOSHAPEHINTS_H
