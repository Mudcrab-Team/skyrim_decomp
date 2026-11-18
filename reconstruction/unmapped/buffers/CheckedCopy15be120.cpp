// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy15be120, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x15be120 CheckedCopy15be120::Copy
#include "CheckedCopy15be120.h"
#include <string.h>
int CheckedCopy15be120::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
