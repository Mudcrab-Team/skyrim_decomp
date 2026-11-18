// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy15e1340, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x15e1340 CheckedCopy15e1340::Copy
#include "CheckedCopy15e1340.h"
#include <string.h>
int CheckedCopy15e1340::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
