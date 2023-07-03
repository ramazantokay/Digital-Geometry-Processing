#ifndef COIN_SOSFVEC4F_H
#define COIN_SOSFVEC4F_H

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

#include <Inventor/fields/SoSField.h>
#include <Inventor/fields/SoSubField.h>
#include <Inventor/SbVec4f.h>

class COIN_DLL_API SoSFVec4f : public SoSField {
  typedef SoSField inherited;

  SO_SFIELD_HEADER(SoSFVec4f, SbVec4f, const SbVec4f &);

public:
  static void initClass(void);

  void setValue(const float x, const float y, const float z, const float w);
  void setValue(const float xyzw[4]);
};

#endif // !COIN_SOSFVEC4F_H
