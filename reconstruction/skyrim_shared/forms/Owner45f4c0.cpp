// Source exposure: mixed. Drafted from the local instruction listings of the
// Code origin: Stamped as a twin of matched 0x146a50 (skyrim_shared/forms/BGSEquipType): source copied, names replaced by placeholders.
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x45f4c0 Owner45f4c0::SetEquipSlot
#include "Owner45f4c0.h"

Owner45f4c0::Owner45f4c0()
{
}

// guess: same compiled code as matched 0x146a50 apart from relocated fields; its role here is not established.
void Owner45f4c0::SetEquipSlot(BGSEquipSlot* a_slot)
{
    equipSlot = a_slot;
}
