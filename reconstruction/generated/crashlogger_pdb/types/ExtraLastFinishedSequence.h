// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraLastFinishedSequence; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSFixedString_char_83b572b4.h"
struct ExtraLastFinishedSequence {
    BSExtraData_4ca6af76 _base;
    BSFixedString_char_83b572b4 lastSequenceName;
};
static_assert(sizeof(ExtraLastFinishedSequence) == 24, "ExtraLastFinishedSequence layout differs from the PDB");
