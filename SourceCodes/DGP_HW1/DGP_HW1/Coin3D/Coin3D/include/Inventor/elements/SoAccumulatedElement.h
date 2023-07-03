#ifndef COIN_SOACCUMULATEDELEMENT_H
#define COIN_SOACCUMULATEDELEMENT_H

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
#include <Inventor/lists/SbList.h>

class COIN_DLL_API SoAccumulatedElement : public SoElement {
  typedef SoElement inherited;

  SO_ELEMENT_ABSTRACT_HEADER(SoAccumulatedElement);
public:
  static void initClass(void);
protected:
  virtual ~SoAccumulatedElement();

public:
  virtual SbBool matches(const SoElement * element) const;

protected:
  void init(SoState * state);
  void push(SoState * state);

  void clearNodeIds(void);
  void addNodeId(const SoNode * const node);
  void setNodeId(const SoNode * const node);
  void copyNodeIds(const SoAccumulatedElement * copyfrom);
  virtual SoElement * copyMatchInfo(void) const;
  virtual void captureThis(SoState * state) const;

  SbList <uint32_t> nodeIds;

private:
  SbBool recursecapture;
};

#endif // !COIN_SOACCUMULATEDELEMENT_H
