// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e8790 Unit1e8790::DeletePayload1e8790
// Adapted bodies: none
#include "Unit1e8790.h"

// Deletes the owned payload under a scoped thread-local context tag.
void Unit1e8790::DeletePayload1e8790()
{
    ScopedContextTag1e8790 guard(0x65);
    delete payload;
}
