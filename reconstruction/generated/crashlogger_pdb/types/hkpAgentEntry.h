// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgentEntry; size 0x4
#pragma once
struct hkpAgentEntry {
    unsigned char m_streamCommand_0;
    unsigned char m_agentType_1;
    unsigned char m_numContactPoints_2;
    unsigned char m_size_3;
};
static_assert(sizeof(hkpAgentEntry) == 4, "hkpAgentEntry layout differs from the PDB");
