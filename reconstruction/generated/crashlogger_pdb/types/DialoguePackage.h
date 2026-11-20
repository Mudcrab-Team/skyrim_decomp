// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialoguePackage; size 0x100
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "TESPackage_986d2eaa.h"
struct DialoguePackage {
    TESPackage_986d2eaa _base;
    unsigned int unk0E0;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 unk0E4;
    BSPointerHandle_RE__Actor_1a35f4b9 unk0E8;
    BSPointerHandle_RE__Actor_1a35f4b9 unk0EC;
    unsigned long long unk0F0;
    unsigned long long unk0F8;
};
static_assert(sizeof(DialoguePackage) == 256, "DialoguePackage layout differs from the PDB");
