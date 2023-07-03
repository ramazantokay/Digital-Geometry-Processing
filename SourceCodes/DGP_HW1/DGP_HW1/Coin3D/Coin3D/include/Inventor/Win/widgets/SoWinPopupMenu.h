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

// src/Inventor/Win/widgets/SoWinPopupMenu.h.  Generated from SoGuiPopupMenu.h.in by configure.

#ifndef SOWIN_POPUPMENU_H
#define SOWIN_POPUPMENU_H

#include <Inventor/SbBasic.h>

#include <Inventor/Win/SoWinComponent.h>

// *************************************************************************

typedef void SoWinMenuSelectionCallback(int itemid, void * user);

class SOWIN_DLL_API SoWinPopupMenu { // abstract interface class
public:
  static SoWinPopupMenu * createInstance(void);
  virtual ~SoWinPopupMenu();

  virtual int newMenu(const char * name, int menuid = -1) = 0;
  virtual int getMenu(const char * name) = 0;
  virtual void setMenuTitle(int id, const char * title) = 0;
  virtual const char * getMenuTitle(int id) = 0;

  virtual int newMenuItem(const char * name, int itemid = -1) = 0;
  virtual int getMenuItem(const char * name) = 0;
  virtual void setMenuItemTitle(int itemid, const char * title) = 0;
  virtual const char * getMenuItemTitle(int itemid) = 0;
  virtual void setMenuItemEnabled(int itemid, SbBool enabled) = 0;
  virtual SbBool getMenuItemEnabled(int itemid) = 0;
  void setMenuItemMarked(int itemid, SbBool marked);
  virtual SbBool getMenuItemMarked(int itemid) = 0;

  virtual void addMenu(int menuid, int submenuid, int pos = -1) = 0;
  virtual void addMenuItem(int menuid, int itemid, int pos = -1) = 0;
  virtual void addSeparator(int menuid, int pos = -1) = 0;
  virtual void removeMenu(int menuid) = 0;
  virtual void removeMenuItem(int itemid) = 0;

  virtual void popUp(HWND inside, int x, int y) = 0;

  int newRadioGroup(int groupid = -1);
  int getRadioGroup(int itemid);
  int getRadioGroupSize(int groupid);
  void addRadioGroupItem(int groupid, int itemid);
  void removeRadioGroupItem(int itemid);

  // FIXME: bad interface. Should be internal/private, and the name is
  // wrong.  According to what this actually does, it should be
  // something like "unmarkOtherOfRadioGroup()". 20050622 mortene.
  void setRadioGroupMarkedItem(int itemid);
#if SOWIN_MAJOR_VERSION == 2
#error fix API above
#endif // SOWIN_MAJOR_VERSION

  int getRadioGroupMarkedItem(int groupid);

  void addMenuSelectionCallback(SoWinMenuSelectionCallback * callback,
                                void * data);
  void removeMenuSelectionCallback(SoWinMenuSelectionCallback * callback,
                                   void * data);

protected:
  SoWinPopupMenu(void);

  virtual void _setMenuItemMarked(int itemid, SbBool marked) = 0;

  void invokeMenuSelection(int itemid);

private:
  class SoWinPopupMenuP * pimpl;

}; // class SoWinPopupMenu

// *************************************************************************

#endif // ! SOWIN_POPUPMENU_H
