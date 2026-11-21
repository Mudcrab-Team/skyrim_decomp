// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LinkedMapping; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "INPUT_CONTEXT_ID.h"
struct LinkedMapping {
    BSFixedString_char_83b572b4 linkedMappingName;
    INPUT_CONTEXT_ID linkedMappingContext;
    unsigned char device_raw[4];
    INPUT_CONTEXT_ID linkFromContext;
    unsigned int pad14;
    BSFixedString_char_83b572b4 linkFromName;
};
static_assert(sizeof(LinkedMapping) == 32, "LinkedMapping layout differs from the PDB");
