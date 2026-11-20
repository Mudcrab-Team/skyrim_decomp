// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDMeter; size 0x48
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "HUDObject.h"
struct HUDMeter {
    HUDObject _base;
    BSFixedString_char_83b572b4 setPctName;
    BSFixedString_char_83b572b4 setBlinkingName;
    BSFixedString_char_83b572b4 fadeOutName;
    float fillPct;
    unsigned int pad44;
};
static_assert(sizeof(HUDMeter) == 72, "HUDMeter layout differs from the PDB");
