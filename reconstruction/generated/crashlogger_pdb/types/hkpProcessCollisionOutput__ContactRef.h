// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionOutput__ContactRef; size 0x18
#pragma once

struct hkpAgentEntry;
struct hkpProcessCdPoint;
struct hkpProcessCollisionOutput__ContactRef {
    hkpProcessCdPoint* m_contactPoint_0;
    hkpAgentEntry* m_agentEntry_8;
    void* m_agentData_10;
};
static_assert(sizeof(hkpProcessCollisionOutput__ContactRef) == 24, "hkpProcessCollisionOutput__ContactRef layout differs from the PDB");
