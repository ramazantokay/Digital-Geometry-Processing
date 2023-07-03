#ifndef COIN_SOPOINTLIGHTMANIP_H
#define COIN_SOPOINTLIGHTMANIP_H

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

#include <Inventor/nodes/SoPointLight.h>
#ifndef COIN_INTERNAL
#include <Inventor/draggers/SoDragger.h>
#endif

class SoChildList;
class SoDragger;
class SoFieldSensor;
class SoPath;
class SoSensor;


class COIN_DLL_API SoPointLightManip : public SoPointLight {
  typedef SoPointLight inherited;

  SO_NODE_HEADER(SoPointLightManip);

public:
  static void initClass(void);
  SoPointLightManip(void);

  SoDragger * getDragger(void);
  SbBool replaceNode(SoPath * path);
  SbBool replaceManip(SoPath * path, SoPointLight * newone) const;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void pick(SoPickAction * action);
  virtual void search(SoSearchAction * action);

  virtual SoChildList * getChildren(void) const;

protected:
  ~SoPointLightManip();

  void setDragger(SoDragger * newdragger);

  virtual void copyContents(const SoFieldContainer * fromfc, SbBool copyconnections);
  static void transferFieldValues(const SoPointLight * from, SoPointLight * to);

  static void valueChangedCB(void * f, SoDragger * d);
  static void fieldSensorCB(void * f, SoSensor * d);

  SoFieldSensor * locationFieldSensor;
  SoFieldSensor * colorFieldSensor;
  SoChildList * children;

private:
  void attachSensors(const SbBool onoff);

};

#endif // !COIN_SOPOINTLIGHTMANIP_H
