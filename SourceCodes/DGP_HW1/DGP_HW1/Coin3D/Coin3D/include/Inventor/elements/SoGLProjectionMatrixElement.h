#ifndef COIN_SOGLPROJECTIONMATRIXELEMENT_H
#define COIN_SOGLPROJECTIONMATRIXELEMENT_H

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

#include <Inventor/elements/SoProjectionMatrixElement.h>

class COIN_DLL_API SoGLProjectionMatrixElement : public SoProjectionMatrixElement {
  typedef SoProjectionMatrixElement inherited;

  SO_ELEMENT_HEADER(SoGLProjectionMatrixElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLProjectionMatrixElement();

public:
  virtual void pop(SoState * state,
                   const SoElement * prevTopElement);

protected:
  virtual void setElt(const SbMatrix & matrix);

private:
  void updategl();
};

#endif // !COIN_SOGLPROJECTIONMATRIXELEMENT_H