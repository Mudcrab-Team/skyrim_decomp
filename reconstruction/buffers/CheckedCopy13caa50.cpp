// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy13caa50, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x13caa50 CheckedCopy13caa50::Copy
#include "CheckedCopy13caa50.h"
#include <string.h>
int CheckedCopy13caa50::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
