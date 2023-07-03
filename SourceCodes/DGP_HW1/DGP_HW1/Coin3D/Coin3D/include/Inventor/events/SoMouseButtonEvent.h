#ifndef COIN_SOMOUSEBUTTONEVENT_H
#define COIN_SOMOUSEBUTTONEVENT_H

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

#include <Inventor/events/SoButtonEvent.h>

#define SO_MOUSE_PRESS_EVENT(EVENT, BUTTON) \
 (SoMouseButtonEvent::isButtonPressEvent(EVENT, SoMouseButtonEvent::BUTTON))

#define SO_MOUSE_RELEASE_EVENT(EVENT, BUTTON) \
 (SoMouseButtonEvent::isButtonReleaseEvent(EVENT, SoMouseButtonEvent::BUTTON))

class COIN_DLL_API SoMouseButtonEvent : public SoButtonEvent {
  typedef SoButtonEvent inherited;

  SO_EVENT_HEADER();

public:
  enum Button {
    ANY, BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5
  };

  SoMouseButtonEvent(void);
  virtual ~SoMouseButtonEvent();

  void setButton(SoMouseButtonEvent::Button button);
  SoMouseButtonEvent::Button getButton(void) const;

  static SbBool isButtonPressEvent(const SoEvent * e,
                                   SoMouseButtonEvent::Button whichButton);
  static SbBool isButtonReleaseEvent(const SoEvent * e,
                                     SoMouseButtonEvent::Button whichButton);

  static void initClass(void);

private:
  Button button;
};

#endif // !COIN_SOMOUSEBUTTONEVENT_H
