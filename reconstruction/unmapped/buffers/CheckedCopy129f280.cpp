// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy129f280, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x129f280 CheckedCopy129f280::Copy
#include "CheckedCopy129f280.h"
#include <string.h>
int CheckedCopy129f280::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
