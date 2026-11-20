// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkVariant; size 0x10
#pragma once

struct hkClass;
struct hkVariant {
    void* m_object_0;
    hkClass* m_class_8;
};
static_assert(sizeof(hkVariant) == 16, "hkVariant layout differs from the PDB");
