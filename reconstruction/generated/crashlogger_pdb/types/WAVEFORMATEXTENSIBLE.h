// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WAVEFORMATEXTENSIBLE; size 0x28
#pragma once

#include "GUID.h"
#include "tWAVEFORMATEX.h"
struct WAVEFORMATEXTENSIBLE {
    tWAVEFORMATEX Format;
    short Samples;
    unsigned int dwChannelMask;
    GUID SubFormat;
};
static_assert(sizeof(WAVEFORMATEXTENSIBLE) == 40, "WAVEFORMATEXTENSIBLE layout differs from the PDB");
