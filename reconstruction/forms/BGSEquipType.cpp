// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
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
