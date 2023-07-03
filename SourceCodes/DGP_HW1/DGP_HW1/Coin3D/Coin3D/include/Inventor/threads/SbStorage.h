#ifndef COIN_SBSTORAGE_H
#define COIN_SBSTORAGE_H

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

#include <Inventor/C/threads/storage.h>

typedef void SbStorageApplyFunc(void * tls, void * closure);

class SbStorage {
public:
  SbStorage(unsigned int size) { this->storage = cc_storage_construct(size); }
  SbStorage(unsigned int size, void (*constr)(void *), void (*destr)(void *))
    { this->storage = cc_storage_construct_etc(size, constr, destr); }
  ~SbStorage(void) { cc_storage_destruct(this->storage); }

  void * get(void) { return cc_storage_get(this->storage); }
  void applyToAll(SbStorageApplyFunc * func, void * closure) {
    cc_storage_apply_to_all(this->storage, 
                            (cc_storage_apply_func*)func, closure);
  }

private:
  cc_storage * storage;
};

#endif // !COIN_SBSTORAGE_H

