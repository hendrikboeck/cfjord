#include "cfjord/memory.h"

vptr_t _copy(const vptr_t src, size_t size) {
  vptr_t dest = NEW_BLK(size);
  memcpy(dest, src, size);
  return dest;
}

vptr_t _copyTo(vptr_t dest, const vptr_t src, size_t size) {
  memcpy(dest, src, size);
  return dest;
}

vptr_t _move(vptr_t src, size_t size) {
  vptr_t dest = _copy(src, size);
  DELETE(src);
  return dest;
}

vptr_t _moveTo(vptr_t dest, vptr_t src, size_t size) {
  _copyTo(dest, src, size);
  DELETE(src);
  return dest;
}