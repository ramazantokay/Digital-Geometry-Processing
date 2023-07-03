#ifndef COIN_SOPOLYGONOFFSET_H
#define COIN_SOPOLYGONOFFSET_H

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

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFBitMask.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/elements/SoPolygonOffsetElement.h>

class COIN_DLL_API SoPolygonOffset : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoPolygonOffset);

public:
  static void initClass(void);
  SoPolygonOffset(void);

  enum Style {
    FILLED = SoPolygonOffsetElement::FILLED,
    LINES = SoPolygonOffsetElement::LINES,
    POINTS = SoPolygonOffsetElement::POINTS
  };

  SoSFFloat factor;
  SoSFFloat units;
  SoSFBitMask styles;
  SoSFBool on;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);

protected:
  virtual ~SoPolygonOffset();
};

#endif // !COIN_SOPOLYGONOFFSET_H
