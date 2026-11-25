// Source exposure: mixed. Drafted from the local instruction listings of the
// Code origin: Stamped as a twin of matched 0x146a50 (skyrim_shared/forms/BGSEquipType): source copied, names replaced by placeholders.
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x43e4e0 Owner43e4e0::SetEquipSlot
#include "Owner43e4e0.h"

Owner43e4e0::Owner43e4e0()
{
}

// guess: same compiled code as matched 0x146a50 apart from relocated fields; its role here is not established.
void Owner43e4e0::SetEquipSlot(BGSEquipSlot* a_slot)
{
    equipSlot = a_slot;
}
