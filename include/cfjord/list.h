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

#ifndef _CFJORD_LIST_H
#define _CFJORD_LIST_H

#include "cfjord/memory.h"
#include "cfjord/types.h"

struct _List {
  vptr_t* array;
  size_t  length;
  size_t  capacity;
};
typedef struct _List* List;

typedef vptr_t* ListIterator;

// PRIVATE FUNCTIONS
List _newList(vptr_t* array, size_t length, size_t capacity);
List _copyShallowList(const List self);
void _expandList(List self);
void _insertList(List self, size_t index, const vptr_t itemPtr,
                 size_t itemSize);
void _cinsertList(List self, const ListIterator iterator, const vptr_t itemPtr,
                  size_t itemSize);
void _emplaceList(List self, size_t index, const vptr_t itemPtr,
                  size_t itemSize);
void _cemplaceList(List self, const ListIterator iterator, const vptr_t itemPtr,
                   size_t itemSize);
void _pushBackList(List self, const vptr_t itemPtr, size_t itemSize);
void _emplaceBackList(List self, const vptr_t itemPtr, size_t itemSize);

// CONSTRUCT - DESTRUCT
List newList();
void deleteList(List self);

// ELEMENT ACCESS
vptr_t  atList(const List self, const size_t index);
vptr_t  frontList(const List self);
vptr_t  backList(const List self);
vptr_t* dataList(const List self);

// ITERATORS
ListIterator cbeginList(const List self);
ListIterator cendList(const List self);
ListIterator catList(const List self, const size_t index);

// CAPACITY
bool_t emptyList(List self);
size_t sizeList(List self);
void   reserveList(List self, const size_t newCapacity);
size_t capacityList(List self);
void   shrinkToFitList(List self);

// MODIFIERS
#define insertList(self, index, item) \
  _insertList(self, index, ADDR(item), sizeof(item))
#define cinsertList(self, iterator, item) \
  _cinsertList(self, iterator, ADDR(item), sizeof(item))
#define emplaceList(self, index, item) \
  _emplaceList(self, index, ADDR(item), sizeof(item))
#define cemplaceList(self, iterator, item) \
  _cemplaceList(self, iterator, ADDR(item), sizeof(item))
#define pushBackList(self, item) _pushBackList(self, ADDR(item), sizeof(item))
#define emplaceBackList(self, item) \
  _emplaceBackList(self, ADDR(item), sizeof(item))
void   clearList(List self);
vptr_t popBackList(List self);
void   resizeList(List self, size_t newLength);
void   swapList(List self, List other);

#endif  // _CFJORD_LIST_H