#ifndef COIN_SOTRANSPARENCYELEMENT_H
#define COIN_SOTRANSPARENCYELEMENT_H

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

#include <Inventor/elements/SoReplacedElement.h>
#include <Inventor/elements/SoLazyElement.h>

class COIN_DLL_API SoTransparencyElement : public SoReplacedElement {
  typedef SoReplacedElement inherited;

  SO_ELEMENT_HEADER(SoTransparencyElement);
public:
  static void initClass(void);
protected:
  virtual ~SoTransparencyElement();

public:
  virtual void init(SoState * state);
  static void set(SoState * const state, SoNode * const node,
                  const int32_t numvalues, const float * const values);
  
  static const SoTransparencyElement * getInstance(SoState *state);

  int32_t getNum(void) const;
  float get(const int index) const;
  const float *getArrayPtr(void) const;

private:
  SoState * state;
  SoColorPacker colorpacker;
};

#endif // !COIN_SOTRANSPARENCYELEMENT_H