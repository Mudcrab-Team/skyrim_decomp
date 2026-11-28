// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xcfc860 Stringcfc860::Stringcfc860
// CI hash: 0xcfc860 ??0Stringcfc860@@QEAA@PEBD@Z
// Adapted bodies: none
#include "Stringcfc860.h"

#include <string.h>

// Constructs a refcounted string from str, sharing g_emptyStringData_cfc860 when empty or null.
Stringcfc860::Stringcfc860(const char* str)
{
    std::size_t length = str != nullptr ? strlen(str) : 0;
    StringData_cfc860* buf;
    if (length != 0) {
        buf = static_cast<StringData_cfc860*>(g_heap_cfc860->Alloc(length + 0x10, nullptr));
        buf->text[length] = 0;
        buf->refCount = 1;
        buf->size = length;
    } else {
        // Atomically retain the shared empty string buffer.
        _InterlockedExchangeAdd(&g_emptyStringData_cfc860.refCount, 1);
        buf = &g_emptyStringData_cfc860;
    }
    memcpy(buf->text, str, length);
    data = buf;
}
