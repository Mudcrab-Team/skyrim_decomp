// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy136fee0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x136fee0 CheckedCopy136fee0::Copy
#include "CheckedCopy136fee0.h"
#include <string.h>
int CheckedCopy136fee0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
