// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy12b7c70, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x12b7c70 CheckedCopy12b7c70::Copy
#include "CheckedCopy12b7c70.h"
#include <string.h>
int CheckedCopy12b7c70::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
