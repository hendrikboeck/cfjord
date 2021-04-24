#include "cfjord/list.h"

// PRIVATE FUNCTIONS
List _newList(vptr_t* array, size_t length, size_t capacity) {
  List self = PNEW(List);

  self->array    = array;
  self->length   = length;
  self->capacity = capacity;
  return self;
}

List _copyShallowList(const List self) {
  return _newList(self->array, self->length, self->capacity);
}

void _expandList(List self) {
  self->capacity *= 2;
  self->array = MOVE_TO(NEW_ARR(vptr_t, self->capacity), self->array,
                        self->length * sizeof(vptr_t));
}

void _insertList(List self, size_t index, const vptr_t itemPtr,
                 size_t itemSize) {
  if (self->length >= self->capacity) _expandList(self);
  if (index != self->length) {
    for (size_t i = self->length; i > index; i++)
      self->array[i] = self->array[i - 1];
  }
  self->array[index] = COPY(itemPtr, itemSize);
  self->length++;
}

void _cinsertList(List self, const ListIterator iterator, const vptr_t itemPtr,
                  size_t itemSize) {
  size_t index = (iterator - cbeginList(self)) / sizeof(vptr_t);
  _insertList(self, index, itemPtr, itemSize);
}
void _emplaceList(List self, size_t index, const vptr_t itemPtr,
                  size_t itemSize) {
  DELETE(self->array[index]);
  self->array[index] = COPY(itemPtr, itemSize);
}

void _cemplaceList(List self, const ListIterator iterator, const vptr_t itemPtr,
                   size_t itemSize) {
  size_t index = (iterator - cbeginList(self)) / sizeof(vptr_t);
  _emplaceList(self, index, itemPtr, itemSize);
}

void _pushBackList(List self, const vptr_t itemPtr, size_t itemSize) {
  _insertList(self, self->length, itemPtr, itemSize);
}

void _emplaceBackList(List self, const vptr_t itemPtr, size_t itemSize) {
  _emplaceList(self, self->length - 1, itemPtr, itemSize);
}

// CONSTRUCT - DESTRUCT
List newList() { return _newList(NEW_ARR(vptr_t, 4), 0, 4); }

void deleteList(List self) {
  for (size_t i = 0; i < self->length; i++) DELETE(self->array[i]);
  DELETE(self);
}

// ELEMENT ACCESS
vptr_t atList(const List self, const size_t index) {
  return self->array[index];
}

vptr_t frontList(const List self) {
  if (emptyList(self)) return NULL;
  return self->array[0];
}

vptr_t backList(const List self) {
  if (emptyList(self)) return NULL;
  return self->array[self->length - 1];
}

vptr_t* dataList(const List self) { return self->array; }

// ITERATORS
ListIterator cbeginList(const List self) { return self->array; }

ListIterator cendList(const List self) {
  return (self->array + self->length * sizeof(vptr_t));
}

ListIterator catList(const List self, const size_t index) {
  return (self->array + index * sizeof(vptr_t));
}

// CAPACITY
bool_t emptyList(List self) { return (bool_t)(self->length == 0); }

size_t sizeList(List self) { return self->length; }

void reserveList(List self, const size_t newCapacity) {
  while (newCapacity > self->capacity) _expandList(self);
}

size_t capacityList(List self) { return self->capacity; }

void shrinkToFitList(List self) {
  self->capacity = self->length;
  self->array    = MOVE_TO(NEW_ARR(vptr_t, self->capacity), self->array,
                        self->capacity * sizeof(vptr_t));
}

// MODIFIERS
void clearList(List self) {
  for (size_t i = 0; i < self->length; i++) DELETE(self->array[i]);
  self->length = 0;
}

vptr_t popBackList(List self) {
  vptr_t item = backList(self);
  self->length--;
  return item;
}

void resizeList(List self, size_t newCapacity) {
  if (newCapacity < self->length)
    for (size_t i = newCapacity - 1; i < self->length; i++)
      DELETE(self->array[i]);
  self->capacity = newCapacity;
  self->array    = MOVE_TO(NEW_ARR(vptr_t, self->capacity), self->array,
                        self->length * sizeof(vptr_t));
}

void swapList(List self, List other) {
  List sCpy = _copyShallowList(self);

  self->array    = other->array;
  self->capacity = other->capacity;
  self->length   = other->length;

  other->array    = sCpy->array;
  other->capacity = sCpy->capacity;
  other->length   = sCpy->capacity;

  DELETE(sCpy);
}