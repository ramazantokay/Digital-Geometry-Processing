#ifndef COIN_SBVEC2F_H
#define COIN_SBVEC2F_H

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

#include <stdio.h>

#include <Inventor/SbBasic.h>

class COIN_DLL_API SbVec2f {
public:
  SbVec2f(void);
  SbVec2f(const float v[2]);
  SbVec2f(const float x, const float y);
  float dot(const SbVec2f & v) const;
  SbBool equals(const SbVec2f & v, const float tolerance) const;
  const float * getValue(void) const;
  void getValue(float & x, float & y) const;
  float length(void) const;
  void negate(void);
  float normalize(void);
  SbVec2f & setValue(const float v[2]);
  SbVec2f & setValue(const float x, const float y);
  float & operator [] (const int i);
  const float & operator [] (const int i) const;
  SbVec2f & operator *= (const float d);
  SbVec2f & operator /= (const float d);
  SbVec2f & operator += (const SbVec2f & u);
  SbVec2f & operator -= (const SbVec2f & u);
  SbVec2f operator-(void) const;

  friend COIN_DLL_API SbVec2f operator * (const SbVec2f & v, const float d);
  friend COIN_DLL_API SbVec2f operator * (const float d, const SbVec2f & v);
  friend COIN_DLL_API SbVec2f operator / (const SbVec2f & v, const float d);
  friend COIN_DLL_API SbVec2f operator + (const SbVec2f & v1, const SbVec2f & v2);
  friend COIN_DLL_API SbVec2f operator - (const SbVec2f & v1, const SbVec2f & v2);
  friend COIN_DLL_API int operator == (const SbVec2f & v1, const SbVec2f & v2);
  friend COIN_DLL_API int operator != (const SbVec2f & v1, const SbVec2f & v2);

  void print(FILE * fp) const;

private:
  float vec[2];
};

COIN_DLL_API SbVec2f operator * (const SbVec2f & v, const float d);
COIN_DLL_API SbVec2f operator * (const float d, const SbVec2f & v);
COIN_DLL_API SbVec2f operator / (const SbVec2f & v, const float d);
COIN_DLL_API SbVec2f operator + (const SbVec2f & v1, const SbVec2f & v2);
COIN_DLL_API SbVec2f operator - (const SbVec2f & v1, const SbVec2f & v2);
COIN_DLL_API int operator == (const SbVec2f & v1, const SbVec2f & v2);
COIN_DLL_API int operator != (const SbVec2f & v1, const SbVec2f & v2);

// *************************************************************************

#endif // !COIN_SBVEC2F_H
