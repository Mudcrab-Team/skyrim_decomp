// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy15e3700, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x15e3700 CheckedCopy15e3700::Copy
#include "CheckedCopy15e3700.h"
#include <string.h>
int CheckedCopy15e3700::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
