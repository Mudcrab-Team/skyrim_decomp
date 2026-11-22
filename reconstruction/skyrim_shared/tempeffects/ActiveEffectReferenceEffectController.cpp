// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5dc660 ActiveEffectReferenceEffectController::SetTarget
// Adapted bodies: none
#include "ActiveEffectReferenceEffectController.h"

// MakeRefHandle: GUESS(low); builds a handle through the declared callee
static std::uint32_t MakeRefHandle(ReferenceTarget* a_target)
{
    std::uint32_t handle;
    CreateRefHandle(&handle, a_target);
    return handle;
}

float ActiveEffectReferenceEffectController::GetElapsedTime()
{
    return owner->elapsed;
}

bool ActiveEffectReferenceEffectController::GetNoInitialFlare()
{
    return TestBit(owner->flags, 4);
}

const NiPoint3& ActiveEffectReferenceEffectController::GetSourcePosition()
{
    return owner->source->position;
}

bool ActiveEffectReferenceEffectController::GetEffectPersists()
{
    return TestBit(GetEffectRefData(owner)->flags, 12);
}

bool ActiveEffectReferenceEffectController::GetGoryVisuals()
{
    return TestBit(GetEffectRefData(owner)->flags, 14);
}

TESEffectShader* ActiveEffectReferenceEffectController::GetHitEffectShader()
{
    ActiveEffectOwner* a_owner = owner;
    const std::uint32_t flags = a_owner->flags;
    if (!TestBit(flags, 1)) {
        return GetEffectShaderForRef(GetEffectRefData(a_owner), TestBit(flags, 12));
    }
    return nullptr;
}

BGSArtObject* ActiveEffectReferenceEffectController::GetHitEffectArt()
{
    ActiveEffectOwner* a_owner = owner;
    const std::uint32_t flags = a_owner->flags;
    if (!TestBit(flags, 2)) {
        return GetEffectArtForRef(GetEffectRefData(a_owner), TestBit(flags, 12));
    }
    return nullptr;
}

// ActiveEffectReferenceEffectController::SetTarget: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
void ActiveEffectReferenceEffectController::SetTarget(ReferenceTarget* a_target)
{
    targetHandle = (a_target == nullptr || (a_target->flags & 0x3FF) != 0)
        ? MakeRefHandle(a_target)
        : gNullHandle;
}
