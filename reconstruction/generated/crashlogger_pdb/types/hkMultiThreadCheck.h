// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMultiThreadCheck; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkMultiThreadCheck {
    unsigned int m_threadId_0;
    int m_stackTraceId_4;
    unsigned short m_markCount_8;
    unsigned short m_markBitStack_A;
};
static_assert(sizeof(hkMultiThreadCheck) == 12, "hkMultiThreadCheck layout differs from the PDB");
