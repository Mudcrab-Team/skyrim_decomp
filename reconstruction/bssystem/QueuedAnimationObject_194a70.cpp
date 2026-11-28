// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x194a70 QueuedAnimationObject::sub_140146D60
#include "QueuedAnimationObject_194a70.h"

// Format a task description using the referenced animation object name.
bool QueuedAnimationObject::sub_140146D60(char* a_buf, std::uint32_t a_size)
{
    FormatTaskDesc(a_buf, a_size, gQueuedAnimFormat, unk90->GetName());
    return true;
}
