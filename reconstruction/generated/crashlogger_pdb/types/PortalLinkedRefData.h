// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PortalLinkedRefData; size 0x8
#pragma once
struct PortalLinkedRefData {
    unsigned char linkedRefs_raw[8];
};
static_assert(sizeof(PortalLinkedRefData) == 8, "PortalLinkedRefData layout differs from the PDB");
