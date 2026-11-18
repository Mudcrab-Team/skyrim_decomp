// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy134f130, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x134f130 CheckedCopy134f130::Copy
#include "CheckedCopy134f130.h"
#include <string.h>
int CheckedCopy134f130::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
