// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy13e7b10, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x13e7b10 CheckedCopy13e7b10::Copy
#include "CheckedCopy13e7b10.h"
#include <string.h>
int CheckedCopy13e7b10::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
