// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// pinned image, with the class layout from the header beside this file. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT) unless labelled in the header.
// 0x146700 BGSEquipType::GetEquipSlot
// 0x146a50 BGSEquipType::SetEquipSlot
#include "BGSEquipType.h"

BGSEquipType::BGSEquipType()
{
}

void BGSEquipType::InitializeDataComponent()
{
    equipSlot = nullptr;
}

void BGSEquipType::ClearDataComponent()
{
}

BGSEquipSlot* BGSEquipType::GetEquipSlot() const
{
    return equipSlot;
}

void BGSEquipType::SetEquipSlot(BGSEquipSlot* a_slot)
{
    equipSlot = a_slot;
}
