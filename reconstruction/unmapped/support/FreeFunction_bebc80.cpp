// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xbebc80 Functionbebc80
// Adapted bodies: none
#include "FreeFunction_bebc80.h"

// Atomically releases a reference on record and deletes it when the last reference drops.
void Functionbebc80(Recordbebc80* record)
{
    if (record != nullptr) {
        // Reference count is decremented atomically across threads.
        if (_InterlockedExchangeAdd(&record->refCount, -1) == 1) {
            delete record;
        }
    }
}
