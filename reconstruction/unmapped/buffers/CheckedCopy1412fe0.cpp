// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1412fe0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1412fe0 CheckedCopy1412fe0::Copy
#include "CheckedCopy1412fe0.h"
#include <string.h>
int CheckedCopy1412fe0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
