// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DIALOGUE_DATA; size 0x4
#pragma once

#include "DIALOGUE_TYPE.h"
struct DIALOGUE_DATA {
    unsigned char topicFlags;  // TopicFlag in the PDB is wider than this slot
    DIALOGUE_TYPE type;
    unsigned short subtype;  // Subtype in the PDB is wider than this slot
};
static_assert(sizeof(DIALOGUE_DATA) == 4, "DIALOGUE_DATA layout differs from the PDB");
