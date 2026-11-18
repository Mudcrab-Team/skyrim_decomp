// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy144cd40, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x144cd40 CheckedCopy144cd40::Copy
#include "CheckedCopy144cd40.h"
#include <string.h>
int CheckedCopy144cd40::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
