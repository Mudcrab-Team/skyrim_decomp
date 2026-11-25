// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: body adapted from a permitted sibling body, bit positions and statics checked against the pinned image listing Stamped as a twin of matched 0x192f10 (bssystem/QueuedModel_192f10): source copied, names replaced by placeholders. Loose twin: constants differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/ModelLoader.cpp:32
// 0xfc6680 Ownerfc6680::Functionfc6680
#include "Ownerfc6680.h"
#include <intrin.h>

// Builds a fresh task key from two shared counters and the key's own middle byte.
void Ownerfc6680::Functionfc6680()
{
    const std::int64_t counter = static_cast<unsigned short>(_InterlockedIncrement(&IOTask::iStaticCounter));  // shared by every loader thread: locked increment
    const auto middle = static_cast<unsigned char>(iKey >> 16);
    const auto offset = static_cast<unsigned int>(_InterlockedIncrement(&IOTask::iStaticOffset));  // shared by every loader thread: locked increment
    iKey = ((((static_cast<std::int64_t>(offset) + 0x300000000LL) << 8) + middle) << 16) + counter;
}
