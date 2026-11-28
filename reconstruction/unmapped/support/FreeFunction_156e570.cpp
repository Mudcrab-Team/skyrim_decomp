// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x156e570 Function156e570
// Adapted bodies: none
#include "FreeFunction_156e570.h"

#include <string.h>

// Clones a refcounted string buffer (header + payload) into a newly allocated copy.
char* Function156e570(const char* source)
{
    if (source == nullptr) {
        return nullptr;
    }
    const StringHeader_156e570* oldHeader = reinterpret_cast<const StringHeader_156e570*>(source) - 1;
    std::size_t capacity = oldHeader->capacity;
    std::size_t length = oldHeader->length;
    StringHeader_156e570* newHeader = AllocRaw_156e570(capacity);
    newHeader->capacity = capacity;
    newHeader->refCount = 1;
    newHeader->length = length;
    char* dest = reinterpret_cast<char*>(newHeader + 1);
    memcpy(dest, source, length + 1);
    return dest;
}
