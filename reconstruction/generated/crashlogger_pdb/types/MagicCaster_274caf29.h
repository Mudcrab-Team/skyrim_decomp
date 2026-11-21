// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicCaster; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_BSSoundHandle_56916cda.h"
struct MagicCaster__VFTable;
struct MagicItem;
struct MagicCaster_274caf29 {
    MagicCaster__VFTable* vftable_MagicCaster_0;
    BSTArray_BSSoundHandle_56916cda SoundHandles_8;
    unsigned int DesiredTargetRefHandle_20;
    char _pad_24[4];
    MagicItem* CastItem_28;
    int State_30;
    float Timer_34;
    float Cost_38;
    float MagnitudeOverride_3C;
    float NextTargetUpdate_40;
    float ProjectileTimer_44;
};
static_assert(sizeof(MagicCaster_274caf29) == 72, "MagicCaster_274caf29 layout differs from the PDB");
