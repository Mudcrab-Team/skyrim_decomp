// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction__CrimeData; size 0x48
#pragma once

#include "TESFaction__CrimeDataValues.h"
struct BGSListForm_bac89fb1;
struct BGSOutfit_fdd71a53;
struct TESObjectREFR;
struct TESFaction__CrimeData {
    TESObjectREFR* FactionJailMarker_0;
    TESObjectREFR* FactionWaitMarker_8;
    TESObjectREFR* FactionStolenContainer_10;
    TESObjectREFR* FactionPlayerInventoryContainer_18;
    BGSListForm_bac89fb1* CrimeGroup_20;
    BGSOutfit_fdd71a53* JailOutfit_28;
    TESFaction__CrimeDataValues CrimeValues_30;
    char _pad_44[4];
};
static_assert(sizeof(TESFaction__CrimeData) == 72, "TESFaction__CrimeData layout differs from the PDB");
