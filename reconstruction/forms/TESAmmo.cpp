// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x2695f0 TESAmmo::GetPlayable
// 0x268ac0 TESAmmo::InitializeData
// 0x2692c0 TESAmmo::SaveGame
#include "TESAmmo.h"

bool TESAmmo::GetPlayable() const
{
    return !TestBit(unk118[0], 1);
}

void TESAmmo::InitializeData()
{
    unk110 = 0;
    *reinterpret_cast<std::uint64_t*>(unk118) = 0;
    unkB8 = ammoDefault;
    InitializeSubobject(unk120, false);
}

void TESAmmo::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    SaveSubobject(unkA0, a_buf);
}
