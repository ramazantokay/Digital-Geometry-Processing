#ifndef COIN_SOSUBDETAIL_H
#define COIN_SOSUBDETAIL_H

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

#include <Inventor/details/SoDetail.h>
#include <assert.h>

// *************************************************************************

#define SO_DETAIL_HEADER(_class_) \
public: \
  virtual SoType getTypeId(void) const; \
  static SoType getClassTypeId(void); \
private: \
  static SoType classTypeId

// *************************************************************************

#define SO_DETAIL_SOURCE(_class_) \
SoType _class_::getTypeId(void) const { return _class_::classTypeId; } \
SoType _class_::getClassTypeId(void) { return _class_::classTypeId; } \
SoType _class_::classTypeId STATIC_SOTYPE_INIT

// *************************************************************************

#define SO_DETAIL_INIT_CLASS(_class_, _parentclass_) \
  do { \
    /* Make sure we only initialize once. */ \
    assert(_class_::classTypeId == SoType::badType()); \
    /* Make sure superclass get initialized before subclass. */ \
    assert(_parentclass_::getClassTypeId() != SoType::badType()); \
    \
    _class_::classTypeId = \
           SoType::createType(_parentclass_::getClassTypeId(), \
                              SO__QUOTE(_class_)); \
  } while (0)

// *************************************************************************

#endif // !COIN_SOSUBDETAIL_H
