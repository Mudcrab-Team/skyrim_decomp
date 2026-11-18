// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1487880, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1487880 CheckedCopy1487880::Copy
#include "CheckedCopy1487880.h"
#include <string.h>
int CheckedCopy1487880::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
