// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1457890, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1457890 CheckedCopy1457890::Copy
#include "CheckedCopy1457890.h"
#include <string.h>
int CheckedCopy1457890::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
