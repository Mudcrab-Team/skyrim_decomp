// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy137a340, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x137a340 CheckedCopy137a340::Copy
#include "CheckedCopy137a340.h"
#include <string.h>
int CheckedCopy137a340::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
