// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLinkedCollidable::CollisionEntry; size 0x10
#pragma once

struct hkpAgentNnEntry;
struct hkpLinkedCollidable;
struct hkpLinkedCollidable__CollisionEntry {
    hkpAgentNnEntry* m_agentEntry_0;
    hkpLinkedCollidable* m_partner_8;
};
static_assert(sizeof(hkpLinkedCollidable__CollisionEntry) == 16, "hkpLinkedCollidable__CollisionEntry layout differs from the PDB");
