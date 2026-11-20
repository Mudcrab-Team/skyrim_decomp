// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSaveDataSystemUtility; size 0x228
#pragma once

#include "BSTEventSource_RE__BSSaveDataEvent_f9d00787.h"
struct BSSaveDataSystemUtility_vtbl;
struct BSSaveDataSystemUtility {
    BSSaveDataSystemUtility_vtbl* __vftable;
    BSTEventSource_RE__BSSaveDataEvent_f9d00787 _base_BSTEventSource_RE_BSSaveDataEvent_;
    unsigned char unk060;
    unsigned char pad061;
    unsigned short pad062;
    unsigned int currentCharacterID;
    unsigned char unk068;
    unsigned char pad069;
    unsigned short pad06A;
    unsigned int pad06C;
    unsigned char entry_raw[416];
    unsigned int unk210;
    unsigned int pad214;
    unsigned long long unk218;
    unsigned long long unk220;
};
static_assert(sizeof(BSSaveDataSystemUtility) == 552, "BSSaveDataSystemUtility layout differs from the PDB");
