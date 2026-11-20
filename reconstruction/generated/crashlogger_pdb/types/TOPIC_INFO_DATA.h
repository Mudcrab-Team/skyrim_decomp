// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TOPIC_INFO_DATA; size 0x4
#pragma once
struct TOPIC_INFO_DATA {
    unsigned short flags;  // TOPIC_INFO_FLAGS in the PDB is wider than this slot
    unsigned short timeUntilReset;
};
static_assert(sizeof(TOPIC_INFO_DATA) == 4, "TOPIC_INFO_DATA layout differs from the PDB");
