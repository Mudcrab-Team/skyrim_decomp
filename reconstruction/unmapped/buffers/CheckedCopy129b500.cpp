// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy129b500, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x129b500 CheckedCopy129b500::Copy
#include "CheckedCopy129b500.h"
#include <string.h>
int CheckedCopy129b500::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
