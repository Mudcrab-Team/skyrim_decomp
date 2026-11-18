// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy135f930, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x135f930 CheckedCopy135f930::Copy
#include "CheckedCopy135f930.h"
#include <string.h>
int CheckedCopy135f930::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
