#ifndef COIN_SOPICKACTION_H
#define COIN_SOPICKACTION_H

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

#include <Inventor/actions/SoAction.h>
#include <Inventor/actions/SoSubAction.h>
#include <Inventor/SbViewportRegion.h>


class COIN_DLL_API SoPickAction : public SoAction {
  typedef SoAction inherited;

  SO_ACTION_HEADER(SoPickAction);

public:
  static void initClass(void);

  void setViewportRegion(const SbViewportRegion & newregion);
  const SbViewportRegion & getViewportRegion(void);

  void enableCulling(const SbBool flag);
  SbBool isCullingEnabled() const;

protected:
  SoPickAction(const SbViewportRegion & viewportregion);
  virtual ~SoPickAction();

  virtual void beginTraversal(SoNode * node);

  SbViewportRegion vpRegion;

private:
  SbBool cullingenabled;
};

#endif // !COIN_SOPICKACTION_H
