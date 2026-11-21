// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTypedBroadPhaseHandlePair; size 0x10
#pragma once

struct hkpBroadPhaseHandle;
struct hkpTypedBroadPhaseHandlePair {
    hkpBroadPhaseHandle* m_a_0;
    hkpBroadPhaseHandle* m_b_8;
};
static_assert(sizeof(hkpTypedBroadPhaseHandlePair) == 16, "hkpTypedBroadPhaseHandlePair layout differs from the PDB");
