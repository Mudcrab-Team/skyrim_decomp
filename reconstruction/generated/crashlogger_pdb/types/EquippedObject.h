// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EquippedObject; size 0x10
#pragma once

struct BGSEquipSlot_15bd99b3;
struct TESForm;
struct EquippedObject {
    TESForm* object;
    BGSEquipSlot_15bd99b3* slot;
};
static_assert(sizeof(EquippedObject) == 16, "EquippedObject layout differs from the PDB");
