// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy12f7890, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x12f7890 CheckedCopy12f7890::Copy
#include "CheckedCopy12f7890.h"
#include <string.h>
int CheckedCopy12f7890::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
