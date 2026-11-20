// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraAnimationSequencer; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct BGSAnimationSequencer;
struct ExtraAnimationSequencer {
    BSExtraData_4ca6af76 _base;
    BGSAnimationSequencer* sequencer;
};
static_assert(sizeof(ExtraAnimationSequencer) == 24, "ExtraAnimationSequencer layout differs from the PDB");
