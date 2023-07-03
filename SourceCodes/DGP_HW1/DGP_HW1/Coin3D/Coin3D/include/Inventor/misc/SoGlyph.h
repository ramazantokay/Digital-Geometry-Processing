#ifndef COIN_SOGLYPH_H
#define COIN_SOGLYPH_H

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

#include <Inventor/SbBasic.h>
#include <Inventor/SbBox2f.h>
#include <Inventor/SbVec2s.h>
#include <Inventor/misc/SoState.h>

class SbName;
class SoGlyphP;

class COIN_DLL_API SoGlyph {
public:

  enum Fonttype {
    FONT2D = 1,
    FONT3D = 2
  };
  
  void unref(void) const;
  
  static const SoGlyph * getGlyph(const char character, const SbName & font);
  
  const SbVec2f * getCoords(void) const;
  const int * getFaceIndices(void) const;
  const int * getEdgeIndices(void) const;
  const int * getNextCWEdge(const int edgeidx) const;
  const int * getNextCCWEdge(const int edgeidx) const;

  float getWidth(void) const;
  const SbBox2f & getBoundingBox(void) const;
  
  static const SoGlyph * getGlyph(SoState * state,
                                  const unsigned int character, 
                                  const SbVec2s & size,
                                  const float angle);
  SbVec2s getAdvance(void) const;
  SbVec2s getKerning(const SoGlyph & rightglyph) const;
  unsigned char * getBitmap(SbVec2s & size, SbVec2s & pos, const SbBool antialiased) const;

protected:
  SoGlyph(void);
  ~SoGlyph();

  void setCoords(SbVec2f * coords, int numcoords = -1);
  void setFaceIndices(int * indices, int numindices = -1);
  void setEdgeIndices(int * indices, int numindices = -1);

private:
  void setFontType(Fonttype type) const;
  static void unrefGlyph(SoGlyph * glyph);

  friend class SoGlyphP;
  SoGlyphP * pimpl;
};

#endif // !COIN_SOGLYPH_H
