#ifndef COIN_SBBOX3S_H
#define COIN_SBBOX3S_H

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

#include <Inventor/SbBasic.h>
#include <Inventor/SbVec3s.h>

class COIN_DLL_API SbBox3s {
public:
  SbBox3s(void);
  SbBox3s(short xmin, short ymin, short zmin, short xmax, short ymax, short zmax);
  SbBox3s(const SbVec3s & minvec, const SbVec3s & maxvec);
  ~SbBox3s(void);

  const SbVec3s & getMin(void) const;
  const SbVec3s & getMax(void) const;
  void extendBy(const SbVec3s & point);
  void extendBy(const SbBox3s & box);
  SbBool intersect(const SbVec3s & point) const;
  SbBool intersect(const SbBox3s & box) const;
  void setBounds(short xmin, short ymin, short zmin, short xmax, short ymax, short zmax);
  void setBounds(const SbVec3s & minvec, const SbVec3s & maxvec);
  void getBounds(short & xmin, short & ymin, 
                 short & zmin, short & xmax, 
                 short & ymax, short & zmax) const;
  void getBounds(SbVec3s & minvec, SbVec3s & maxvec) const;
  void getOrigin(short & originX, short & originY, short & originZ) const;
  void getSize(short & sizeX, short & sizeY, short & sizeZ) const;
  void makeEmpty(void);

  friend COIN_DLL_API int operator ==(const SbBox3s & b1, const SbBox3s & b2);
  friend COIN_DLL_API int operator !=(const SbBox3s & b1, const SbBox3s & b2);

private:
  SbVec3s minpt, maxpt;

  short width(void) const;
  short height(void) const;
  short depth(void) const;
  SbBool hasArea(void) const;
};

COIN_DLL_API int operator ==(const SbBox3s & b1, const SbBox3s & b2);
COIN_DLL_API int operator !=(const SbBox3s & b1, const SbBox3s & b2);

#endif // !COIN_SBBOX3S_H
