// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CollisionEntry; size 0x10
#pragma once

struct hkpAgentNnEntry_36ebb4e9;
struct hkpLinkedCollidable_99608242;
struct CollisionEntry {
    hkpAgentNnEntry_36ebb4e9* agentEntry;
    hkpLinkedCollidable_99608242* partner;
};
static_assert(sizeof(CollisionEntry) == 16, "CollisionEntry layout differs from the PDB");
