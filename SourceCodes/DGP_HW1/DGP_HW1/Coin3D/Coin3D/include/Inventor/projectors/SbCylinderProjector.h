#ifndef COIN_SBCYLINDERPROJECTOR_H
#define COIN_SBCYLINDERPROJECTOR_H

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

#include <Inventor/projectors/SbProjector.h>
#include <Inventor/SbCylinder.h>

class COIN_DLL_API SbCylinderProjector : public SbProjector {
  typedef SbProjector inherited;

public:
  virtual SbVec3f project(const SbVec2f & point) = 0;
  SbVec3f projectAndGetRotation(const SbVec2f & point, SbRotation & rot);
  virtual SbRotation getRotation(const SbVec3f & point1,
                                 const SbVec3f & point2) = 0;
  void setCylinder(const SbCylinder & cyl);
  const SbCylinder & getCylinder(void) const;
  void setOrientToEye(const SbBool orienttoeye);
  SbBool isOrientToEye(void) const;
  void setFront(const SbBool infront);
  SbBool isFront(void) const;
  SbBool isPointInFront(const SbVec3f & point) const;
  virtual void setWorkingSpace(const SbMatrix & space);

protected:
  SbCylinderProjector(const SbBool orienttoeye);
  SbCylinderProjector(const SbCylinder & cylinder, const SbBool orienttoeye);

  SbBool intersectCylinderFront(const SbLine & line, SbVec3f & result);

  SbBool intersectFront;
  SbCylinder cylinder;
  SbBool orientToEye;
  SbBool needSetup;
  SbVec3f lastPoint;
};

#endif // !COIN_SBCYLINDERPROJECTOR_H
