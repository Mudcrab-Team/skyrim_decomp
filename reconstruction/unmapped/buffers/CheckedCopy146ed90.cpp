// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy146ed90, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x146ed90 CheckedCopy146ed90::Copy
#include "CheckedCopy146ed90.h"
#include <string.h>
int CheckedCopy146ed90::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
