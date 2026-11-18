// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy145b220, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x145b220 CheckedCopy145b220::Copy
#include "CheckedCopy145b220.h"
#include <string.h>
int CheckedCopy145b220::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
