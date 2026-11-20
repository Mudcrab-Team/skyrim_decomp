// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1362e20, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1362e20 CheckedCopy1362e20::Copy
#include "CheckedCopy1362e20.h"
#include <string.h>
int CheckedCopy1362e20::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
