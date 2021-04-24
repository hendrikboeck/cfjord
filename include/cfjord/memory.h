/******************************************************************************/
/* cfjord                                                                     */
/* Copyright (C) 2021  Hendrik Boeck <hendrikboeck.dev@protonmail.com>        */
/*                                                                            */
/* This program is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by       */
/* the Free Software Foundation, either version 3 of the License, or          */
/* (at your option) any later version.                                        */
/*                                                                            */
/* This program is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of             */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              */
/* GNU General Public License for more details.                               */
/*                                                                            */
/* You should have received a copy of the GNU General Public License          */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.      */
/******************************************************************************/

#ifndef _CFJORD_MEMORY_H
#define _CFJORD_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <memory.h>
#include <stdlib.h>

#include "cfjord/types.h"

#define ADDR(obj)             (&(obj))
#define VPTR_CAST(type, vPtr) (*((type*)vPtr))
#define NEW_BLK(size)         malloc(size)
#define PNEW(ptrType)         ((ptrType)NEW_BLK(sizeof(*((ptrType)NULL))))
#define NEW(type)             ((type*)NEW_BLK(sizeof(type)))
#define NEW_ARR(type, n)      ((type*)NEW_BLK(sizeof(type) * n))
#define DELETE(ptr)           free(ptr)

vptr_t _copy(const vptr_t src, size_t size);
vptr_t _copyTo(vptr_t dest, const vptr_t src, size_t size);
vptr_t _move(vptr_t src, size_t size);
vptr_t _moveTo(vptr_t dest, vptr_t src, size_t size);

#define COPY(src, size)          _copy(src, size)
#define COPY_TO(dest, src, size) _copyTo(dest, src, size)
#define MOVE(src, size)          _move(src, size)
#define MOVE_TO(dest, src, size) _moveTo(dest, src, size)

#ifdef __cplusplus
}
#endif

#endif  // _CFJORD_MEMORY_H