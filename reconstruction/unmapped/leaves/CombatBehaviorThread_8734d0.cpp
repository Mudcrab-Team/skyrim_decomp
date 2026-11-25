// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x8734d0 CombatBehaviorThread::Load
// Adapted bodies: CombatBehaviorThread::Load from the sibling source named in the header
#include "CombatBehaviorThread_8734d0.h"

void CombatBehaviorThread::Load(BGSLoadFormBuffer* a_buffer, CombatBehaviorThread* a_thread)
{
    std::uint32_t size = a_buffer->LoadVariableSizedValue();
    std::uint32_t start = a_buffer->iBufferPosition;
    a_thread->LoadGame(a_buffer);
    if (a_buffer->iBufferPosition < start + size) {
        a_buffer->iBufferPosition = start + size;
    }
}
