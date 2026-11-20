// Source exposure: binary-analysis; pinned compiler headers used normally, not copied.
// Original reconstruction: wrapper; no external implementation adapted into this file.
// CheckedCopy1414270, Copy, destination, destinationSize, source, count: GUESS(low) STANDIN
// 0x1414270 CheckedCopy1414270::Copy
#include "CheckedCopy1414270.h"
#include <string.h>
int CheckedCopy1414270::Copy(void* destination, unsigned __int64 destinationSize, const void* source, unsigned __int64 count) {
    return memcpy_s(destination, destinationSize, source, count);
}
