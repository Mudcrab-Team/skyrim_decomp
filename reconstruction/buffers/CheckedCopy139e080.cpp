// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy139e080, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x139e080 CheckedCopy139e080::Copy
#include "CheckedCopy139e080.h"
#include <string.h>
int CheckedCopy139e080::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
