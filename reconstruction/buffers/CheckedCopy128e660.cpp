// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy128e660, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x128e660 CheckedCopy128e660::Copy
#include "CheckedCopy128e660.h"
#include <string.h>
int CheckedCopy128e660::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
