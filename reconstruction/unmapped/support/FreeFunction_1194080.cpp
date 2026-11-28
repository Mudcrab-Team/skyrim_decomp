// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1194080 Function1194080
// Adapted bodies: none
#include "FreeFunction_1194080.h"

// Computes used space by subtracting shifted granule space and freeSpace from footprint.
// The community name table calls this Scaleform::HeapPT::AllocEngine::GetUsedSpace (a hint, not proof); the names in this unit are stand-ins.
std::size_t Function1194080(const AllocEngine_1194080* engine)
{
    return engine->footprint - (engine->granuleCount << engine->shift) - engine->freeSpace;
}
