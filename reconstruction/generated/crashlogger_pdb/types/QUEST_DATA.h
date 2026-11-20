// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QUEST_DATA; size 0x8
#pragma once
struct QUEST_DATA {
    float questDelayTime;
    unsigned short flags;  // QuestFlag in the PDB is wider than this slot
    unsigned char priority;
    unsigned char questType;  // Type in the PDB is wider than this slot
};
static_assert(sizeof(QUEST_DATA) == 8, "QUEST_DATA layout differs from the PDB");
