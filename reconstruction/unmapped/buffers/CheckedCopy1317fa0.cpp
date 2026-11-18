// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1317fa0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1317fa0 CheckedCopy1317fa0::Copy
#include "CheckedCopy1317fa0.h"
#include <string.h>
int CheckedCopy1317fa0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
