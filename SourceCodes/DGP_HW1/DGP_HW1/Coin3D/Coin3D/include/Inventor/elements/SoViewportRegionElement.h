#ifndef COIN_SOVIEWPORTREGIONELEMENT_H
#define COIN_SOVIEWPORTREGIONELEMENT_H

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

#include <Inventor/elements/SoSubElement.h>
#include <Inventor/SbViewportRegion.h>

class COIN_DLL_API SoViewportRegionElement : public SoElement {
  typedef SoElement inherited;

  SO_ELEMENT_HEADER(SoViewportRegionElement);
public:
  static void initClass(void);
protected:
  virtual ~SoViewportRegionElement();

public:
  virtual void init(SoState * state);
  virtual SbBool matches(const SoElement * element) const;
  virtual SoElement *copyMatchInfo() const;

  static void set(SoState * const state,
                  const SbViewportRegion & viewportRegion);
  static const SbViewportRegion &get(SoState * const state);

  virtual void print(FILE * file) const;

protected:
  virtual void setElt(const SbViewportRegion & viewportRegion);
  SbViewportRegion viewportRegion;

private:
  // this variable is not used, and is present in Coin-2 for ABI
  // compatibility reasons only
  static  SbViewportRegion *emptyViewportRegion;
};

#endif // !COIN_SOVIEWPORTREGIONELEMENT_H
