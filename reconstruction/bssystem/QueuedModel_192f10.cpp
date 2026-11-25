// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body adapted from a permitted sibling body, bit positions and statics checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x192f10 QueuedModel::GenerateKey
// Adapted bodies: QueuedModel::GenerateKey
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/ModelLoader.cpp:32
#include "QueuedModel_192f10.h"

#include <intrin.h>

// Builds a fresh task key from two shared counters and the key's own middle byte.
void QueuedModel::GenerateKey()
{
    const std::int64_t counter = static_cast<unsigned short>(_InterlockedIncrement(&IOTask::iStaticCounter));  // shared by every loader thread: locked increment
    const auto middle = static_cast<unsigned char>(iKey >> 16);
    const auto offset = static_cast<unsigned int>(_InterlockedIncrement(&IOTask::iStaticOffset));  // shared by every loader thread: locked increment
    iKey = ((((static_cast<std::int64_t>(offset) + 0x100000000LL) << 8) + middle) << 16) + counter;
}
