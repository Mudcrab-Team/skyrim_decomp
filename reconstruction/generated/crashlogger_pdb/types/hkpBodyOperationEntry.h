// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBodyOperationEntry; size 0x18
#pragma once

struct hkpBodyOperation;
struct hkpEntity_b3bc9432;
struct hkpBodyOperationEntry {
    hkpEntity_b3bc9432* m_entity_0;
    hkpBodyOperation* m_operation_8;
    int m_priority_10;
    int m_hint_14;
};
static_assert(sizeof(hkpBodyOperationEntry) == 24, "hkpBodyOperationEntry layout differs from the PDB");
