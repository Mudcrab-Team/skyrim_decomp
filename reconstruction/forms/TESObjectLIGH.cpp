// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x275080 TESObjectLIGH::Activate
// 0x275210 TESObjectLIGH::SaveGame
#include "TESObjectLIGH.h"

// Body done: RVA 0x275080, 20 bytes, TESObjectLIGH::Activate. The fallback is a tail call in the
// target when the flag is set, and false otherwise.
bool TESObjectLIGH::Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount)
{
    if (!TestBit(unknownEC, 1)) {
        return false;
    }
    return TESBoundObject::Activate(a_targetRef, a_activatorRef, a_arg3, a_object, a_targetCount);
}

// Body done: RVA 0x275210, 46 bytes, TESObjectLIGH::SaveGame. The base save runs first; the
// sub-object save is the last call, a tail call in the target.
void TESObjectLIGH::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    SaveValueState(unknownB0, a_buf);
}
