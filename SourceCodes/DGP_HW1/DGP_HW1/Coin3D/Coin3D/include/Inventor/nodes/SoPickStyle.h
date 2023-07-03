#ifndef COIN_SOPICKSTYLE_H
#define COIN_SOPICKSTYLE_H

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

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/elements/SoPickStyleElement.h>

class COIN_DLL_API SoPickStyle : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoPickStyle);

public:
  static void initClass(void);
  SoPickStyle(void);

  enum Style {
    SHAPE = SoPickStyleElement::SHAPE,
    BOUNDING_BOX = SoPickStyleElement::BOUNDING_BOX,
    UNPICKABLE = SoPickStyleElement::UNPICKABLE
  };

  SoSFEnum style;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void pick(SoPickAction * action);

protected:
  virtual ~SoPickStyle();
};

#endif // !COIN_SOPICKSTYLE_H
