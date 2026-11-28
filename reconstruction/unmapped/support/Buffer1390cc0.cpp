// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1390cc0 Buffer1390cc0::~Buffer1390cc0
// CI hash: 0x1390cc0 ??1Buffer1390cc0@@QEAA@XZ
// Adapted bodies: none
#include "Buffer1390cc0.h"

// Resets inner range and clears extra before InnerBuffer_1390cc0 releases storage.
Buffer1390cc0::~Buffer1390cc0()
{
    inner.Clear();
    extra = nullptr;
}
