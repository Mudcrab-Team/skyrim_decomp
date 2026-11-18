// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1437150, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1437150 CheckedCopy1437150::Copy
#include "CheckedCopy1437150.h"
#include <string.h>
int CheckedCopy1437150::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
