// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkClipTrigger; size 0x20
#pragma once

#include "hkbEventProperty.h"
struct hkClipTrigger {
    float localTime;
    unsigned char undefined_4[4];
    hkbEventProperty event;
    bool relativeToEndOfClip;
    bool acyclic;
    bool isAnnotation;
    unsigned char undefined_1b[5];
};
static_assert(sizeof(hkClipTrigger) == 32, "hkClipTrigger layout differs from the PDB");
