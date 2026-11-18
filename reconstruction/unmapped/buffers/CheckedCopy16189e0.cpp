// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy16189e0, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x16189e0 CheckedCopy16189e0::Copy
#include "CheckedCopy16189e0.h"
#include <string.h>
int CheckedCopy16189e0::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
