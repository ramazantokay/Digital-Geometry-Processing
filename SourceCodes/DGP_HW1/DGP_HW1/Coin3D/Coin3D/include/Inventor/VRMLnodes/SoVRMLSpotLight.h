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

#ifndef COIN_SOVRMLSPOTLIGHT_H
#define COIN_SOVRMLSPOTLIGHT_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/VRMLnodes/SoVRMLLight.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFFloat.h>

class COIN_DLL_API SoVRMLSpotLight : public SoVRMLLight
{
  typedef SoVRMLLight inherited;
  SO_NODE_HEADER(SoVRMLSpotLight);

public:
  static void initClass(void);
  SoVRMLSpotLight(void);

  SoSFVec3f location;
  SoSFVec3f direction;
  SoSFFloat beamWidth;
  SoSFFloat cutOffAngle;
  SoSFFloat radius;
  SoSFVec3f attenuation;

  virtual void GLRender( SoGLRenderAction * action );

protected:
  virtual ~SoVRMLSpotLight();

}; // class SoVRMLSpotLight

#endif // ! COIN_SOVRMLSPOTLIGHT_H
