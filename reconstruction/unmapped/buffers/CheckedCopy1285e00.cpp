// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1285e00, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1285e00 CheckedCopy1285e00::Copy
#include "CheckedCopy1285e00.h"
#include <string.h>
int CheckedCopy1285e00::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
