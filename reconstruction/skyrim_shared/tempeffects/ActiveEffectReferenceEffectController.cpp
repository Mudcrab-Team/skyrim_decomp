// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x5dc6d0 ActiveEffectReferenceEffectController::GetElapsedTime
// 0x5dc7f0 ActiveEffectReferenceEffectController::GetNoInitialFlare
// 0x5dc760 ActiveEffectReferenceEffectController::GetSourcePosition
// 0x5dc810 ActiveEffectReferenceEffectController::GetEffectPersists
// 0x5dc830 ActiveEffectReferenceEffectController::GetGoryVisuals
// 0x5dc990 ActiveEffectReferenceEffectController::GetHitEffectShader
// 0x5dc950 ActiveEffectReferenceEffectController::GetHitEffectArt
// 0x5dc660 ActiveEffectReferenceEffectController::SetTarget
#include "ActiveEffectReferenceEffectController.h"

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
