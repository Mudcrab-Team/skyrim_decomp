// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy13d7490, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x13d7490 CheckedCopy13d7490::Copy
#include "CheckedCopy13d7490.h"
#include <string.h>
int CheckedCopy13d7490::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
