// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x5dc660 (skyrim_shared/tempeffects/ActiveEffectReferenceEffectController): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x46bd20 Owner46bd20::Function46bd20
#include "Owner46bd20.h"

// MakeRefHandle: GUESS(low); builds a handle through the declared callee
static std::uint32_t MakeRefHandle(ReferenceTarget* a_target)
{
    std::uint32_t handle;
    CreateRefHandle(&handle, a_target);
    return handle;
}

// Owner46bd20::Function46bd20: GUESS(low) STANDIN
void Owner46bd20::Function46bd20(ReferenceTarget* a_target)
{
    targetHandle = (a_target == nullptr || (a_target->flags & 0x3FF) != 0)
        ? MakeRefHandle(a_target)
        : gNullHandle;
}
