// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy15d3670, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x15d3670 CheckedCopy15d3670::Copy
#include "CheckedCopy15d3670.h"
#include <string.h>
int CheckedCopy15d3670::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
