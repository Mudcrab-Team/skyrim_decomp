// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy133e350, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x133e350 CheckedCopy133e350::Copy
#include "CheckedCopy133e350.h"
#include <string.h>
int CheckedCopy133e350::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
