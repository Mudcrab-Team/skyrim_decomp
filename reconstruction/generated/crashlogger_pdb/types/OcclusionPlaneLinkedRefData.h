// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OcclusionPlaneLinkedRefData; size 0x10
#pragma once
struct OcclusionPlaneLinkedRefData {
    unsigned char linkedRefs_raw[16];
};
static_assert(sizeof(OcclusionPlaneLinkedRefData) == 16, "OcclusionPlaneLinkedRefData layout differs from the PDB");
