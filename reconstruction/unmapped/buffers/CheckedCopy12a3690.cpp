// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy12a3690, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x12a3690 CheckedCopy12a3690::Copy
#include "CheckedCopy12a3690.h"
#include <string.h>
int CheckedCopy12a3690::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
