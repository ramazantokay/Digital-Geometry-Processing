#ifndef COIN_SOSHAPESTYLEELEMENT_H
#define COIN_SOSHAPESTYLEELEMENT_H

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

class COIN_DLL_API SoShapeStyleElement : public SoElement {
  typedef SoElement inherited;

  SO_ELEMENT_HEADER(SoShapeStyleElement);
public:
  static void initClass(void);
protected:
  virtual ~SoShapeStyleElement();

public:

  // flags used for optimized testing of features
  enum Flags {
    LIGHTING                = 0x000100,
    TEXENABLED              = 0x000200,
    TEXFUNC                 = 0x000400,
    BBOXCMPLX               = 0x000800,
    INVISIBLE               = 0x001000,
    ABORTCB                 = 0x002000,
    OVERRIDE                = 0x004000,
    TEX3ENABLED             = 0x008000,
    BIGIMAGE                = 0x010000,
    BUMPMAP                 = 0x020000,
    VERTEXARRAY             = 0x040000,
    TRANSP_TEXTURE          = 0x080000,
    TRANSP_MATERIAL         = 0x100000,
    TRANSP_SORTED_TRIANGLES = 0x200000
  };
  
  virtual void init(SoState * state);

  virtual void push(SoState * state);
  virtual void pop(SoState * state, const SoElement * prevTopElement);

  virtual SbBool matches(const SoElement * element) const;
  virtual SoElement * copyMatchInfo(void) const;

  static const SoShapeStyleElement * get(SoState * const state);

  unsigned int getFlags(void) const;
  SbBool mightNotRender(void) const;
  SbBool needNormals(void) const;
  SbBool needTexCoords(void) const;
  int getRenderCaseMask(void) const;

  static void setDrawStyle(SoState * const state, const int32_t value);
  static void setComplexityType(SoState * const state,
                                const int32_t value);
  static void setTransparencyType(SoState * const state,
                                  const int32_t value);
  static void setTextureEnabled(SoState * const state, const SbBool value);
  static void setTexture3Enabled(SoState * const state, const SbBool value);
  static void setTextureFunction(SoState * const state,
                                 const SbBool value);
  static void setLightModel(SoState * const state, const int32_t value);
  static void setOverrides(SoState * const state, const SbBool value);

  static SbBool isScreenDoor(SoState * const state);
  static int getTransparencyType(SoState * const state);
  SbBool isTextureFunction(void) const;

  static void setBumpmapEnabled(SoState * state, const SbBool value);
  static void setBigImageEnabled(SoState * state, const SbBool value);
  static void setVertexArrayRendering(SoState * state, const SbBool value);

  static void setTransparentMaterial(SoState * state, const SbBool value);
  static void setTransparentTexture(SoState * state, const SbBool value);

private:

  static SoShapeStyleElement * getElement(SoState * const state);
  static const SoShapeStyleElement * getConstElement(SoState * const state);

  unsigned int flags;
};

#endif // !COIN_SOSHAPESTYLEELEMENT_H
