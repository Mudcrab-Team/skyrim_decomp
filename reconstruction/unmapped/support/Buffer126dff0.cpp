// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x126dff0 Buffer126dff0::~Buffer126dff0
// CI hash: 0x126dff0 ??1Buffer126dff0@@QEAA@XZ
// Adapted bodies: none
#include "Buffer126dff0.h"

// Resets inner range and clears extra before InnerBuffer_126dff0 releases storage.
Buffer126dff0::~Buffer126dff0()
{
    inner.Clear();
    extra = nullptr;
}
