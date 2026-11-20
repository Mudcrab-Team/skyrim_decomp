// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x286eb0 TESObjectMISC::SaveGame
#include "TESObjectMISC.h"

void TESObjectMISC::SaveGame(BGSSaveFormBuffer* a_buf)
{
    TESForm::SaveGame(a_buf);
    saveBlock88.SaveData(a_buf);
}
