// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy143f3c0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x143f3c0 CheckedCopy143f3c0::Copy
#include "CheckedCopy143f3c0.h"
#include <string.h>
int CheckedCopy143f3c0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
