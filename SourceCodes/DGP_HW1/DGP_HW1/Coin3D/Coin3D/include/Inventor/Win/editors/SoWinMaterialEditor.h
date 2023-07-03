#ifndef COIN_SOWINMATERIALEDITOR_H
#define COIN_SOWINMATERIALEDITOR_H

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

#include <Inventor/Win/nodes/SoGuiMaterialEditor.h>
#include <Inventor/Win/SoWinRenderArea.h>

class SoMaterial;
class SoVRMLMaterial;

// *************************************************************************

typedef void SoWinMaterialEditorCB(void * userdata, const SoMaterial * material);

class SOWIN_DLL_API SoWinMaterialEditor : public SoWinRenderArea {
  SOWIN_OBJECT_HEADER(SoWinMaterialEditor, SoWinRenderArea);

public:
  SoWinMaterialEditor(HWND parent = NULL, const char * name = NULL, SbBool embed = TRUE);
  ~SoWinMaterialEditor(void);

  enum UpdateFrequency {
    CONTINUOUS = SoGuiMaterialEditor::CONTINUOUS,
    AFTER_ACCEPT = SoGuiMaterialEditor::AFTER_ACCEPT
  };

  void attach(SoMaterial * material, int index = 0);
  void attach(SoVRMLMaterial * material);
  void detach(void);
  SbBool isAttached(void);

  void addMaterialChangedCallback(
    SoWinMaterialEditorCB * callback, void * closure = NULL);
  void removeMaterialChangedCallback(
    SoWinMaterialEditorCB * callback, void * closure = NULL);

  void setUpdateFrequency(SoWinMaterialEditor::UpdateFrequency frequency);
  SoWinMaterialEditor::UpdateFrequency getUpdateFrequency(void) const;

  void setMaterial(const SoMaterial & material);
  void setMaterial(const SoVRMLMaterial & material);
  const SoMaterial & getMaterial(void) const;
  SbBool isAttachedVRML(void);

  SoGuiMaterialEditor * getEditor(void) const;

protected:
  SoWinMaterialEditor(HWND parent, const char * const name, SbBool embed, SbBool build);

  virtual const char * getDefaultWidgetName(void) const;
  virtual const char * getDefaultTitle(void) const;
  virtual const char * getDefaultIconTitle(void) const;

private:
  void * internals;

}; // class SoWinMaterialEditor

// *************************************************************************

#endif // !COIN_SOWINMATERIALEDITOR_H
