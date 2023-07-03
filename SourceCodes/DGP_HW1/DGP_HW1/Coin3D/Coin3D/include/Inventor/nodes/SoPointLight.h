#ifndef COIN_SOPOINTLIGHT_H
#define COIN_SOPOINTLIGHT_H

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
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/nodes/SoLight.h>

class COIN_DLL_API SoPointLight : public SoLight {
  typedef SoLight inherited;

  SO_NODE_HEADER(SoPointLight);

public:
  static void initClass(void);
  SoPointLight(void);

  SoSFVec3f location;

  virtual void GLRender(SoGLRenderAction * action);

protected:
  virtual ~SoPointLight();
};

#endif // !COIN_SOPOINTLIGHT_H
