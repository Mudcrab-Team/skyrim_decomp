// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMultiThreadCheck; size 0xc
// one of 2 different PDB types sharing this name
#pragma once
struct hkMultiThreadCheck_64f82694 {
    unsigned int threadId;
    int stackTraceId;
    unsigned short markCount;
    unsigned short markBitStack;
};
static_assert(sizeof(hkMultiThreadCheck_64f82694) == 12, "hkMultiThreadCheck_64f82694 layout differs from the PDB");
