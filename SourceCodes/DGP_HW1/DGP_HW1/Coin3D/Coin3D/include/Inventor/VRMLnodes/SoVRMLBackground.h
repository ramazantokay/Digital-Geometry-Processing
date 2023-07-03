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

#ifndef COIN_SOVRMLBACKGROUND_H
#define COIN_SOVRMLBACKGROUND_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoMFColor.h>
#include <Inventor/fields/SoMFFloat.h>
#include <Inventor/fields/SoMFString.h>
#include <Inventor/fields/SoSFBool.h>

class SoVRMLBackgroundP;

class COIN_DLL_API SoVRMLBackground : public SoNode
{
  typedef SoNode inherited;
  SO_NODE_HEADER(SoVRMLBackground);

public:
  static void initClass(void);
  SoVRMLBackground(void);

  SoMFColor groundColor;
  SoMFFloat groundAngle;
  SoMFColor skyColor;
  SoMFFloat skyAngle;
  SoMFString backUrl;
  SoMFString bottomUrl;
  SoMFString frontUrl;
  SoMFString leftUrl;
  SoMFString rightUrl;
  SoMFString topUrl;

  virtual void GLRender( SoGLRenderAction * action );

protected:
  virtual ~SoVRMLBackground();

  SoSFBool set_bind; // eventIn
  SoSFBool isBound;  // eventOut

private:
  SoVRMLBackgroundP * pimpl;

};

#endif // ! COIN_SOVRMLBACKGROUND_H
