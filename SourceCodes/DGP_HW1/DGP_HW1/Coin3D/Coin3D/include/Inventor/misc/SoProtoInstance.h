#ifndef COIN_SOPROTOINSTANCE_H
#define COIN_SOPROTOINSTANCE_H

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

// NB: This is work-in-progress, and the API might change from day to
// day. Do not use this class unless you are prepared for this.
// pederb, 2002-05-28

#include <Inventor/nodes/SoNode.h>
#include <Inventor/nodes/SoSubNode.h>

class SoProto;
class SoSensor;

class COIN_DLL_API SoProtoInstance : public SoNode {
  typedef SoNode inherited;

  // The following definitions are used instead of SO_NODE_HEADER() to
  // let SoProtoInstance have dynamic handling of SoFieldData objects.

  PRIVATE_NODE_TYPESYSTEM_HEADER();
protected:
  virtual const SoFieldData * getFieldData(void) const;
private:
  SoFieldData * classfielddata;

public:
  static void initClass(void);

  SoProtoInstance(SoProto * proto,
                  const SoFieldData * deffielddata);

  static SoProtoInstance * findProtoInstance(const SoNode * rootnode); 
  void setRootNode(SoNode * root);
  SoNode * getRootNode(void);

  SoProto * getProtoDefinition(void) const;
  SbName getProtoName(void) const;
  
  virtual void write(SoWriteAction * action);

protected:
  virtual ~SoProtoInstance();
  virtual SbBool readInstance(SoInput * in, unsigned short flags);
  virtual const char * getFileFormatName(void) const;

private:

  static void sensorCB(void * data, SoSensor * sensor);
  static void cleanupClass(void);
  void copyFieldData(const SoFieldData * src);

  class SoProtoInstanceP * pimpl;
};

#endif // !COIN_SOPROTOINSTANCE_H

