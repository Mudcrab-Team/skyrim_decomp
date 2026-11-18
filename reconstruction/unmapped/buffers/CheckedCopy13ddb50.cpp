// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy13ddb50, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x13ddb50 CheckedCopy13ddb50::Copy
#include "CheckedCopy13ddb50.h"
#include <string.h>
int CheckedCopy13ddb50::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
