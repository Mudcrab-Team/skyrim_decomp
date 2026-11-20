// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActionOutput; size 0x30
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct TESIdleForm_2b3518b0;
struct ActionOutput {
    BSFixedString_char_83b572b4 animEvent;
    BSFixedString_char_83b572b4 targetAnimEvent;
    int result;
    unsigned char undefined_14[4];
    TESIdleForm_2b3518b0* sequence;
    TESIdleForm_2b3518b0* animObjIdle;
    unsigned int sequenceIndex;
    unsigned char undefined_2c[4];
};
static_assert(sizeof(ActionOutput) == 48, "ActionOutput layout differs from the PDB");
