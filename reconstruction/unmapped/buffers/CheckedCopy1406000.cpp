// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1406000, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1406000 CheckedCopy1406000::Copy
#include "CheckedCopy1406000.h"
#include <string.h>
int CheckedCopy1406000::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
