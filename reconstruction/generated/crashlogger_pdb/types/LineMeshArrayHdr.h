// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LineMeshArrayHdr; size 0x18
#pragma once
struct LineMeshArrayHdr {
    void* data;
    unsigned long long size;
    unsigned long long capacity;
};
static_assert(sizeof(LineMeshArrayHdr) == 24, "LineMeshArrayHdr layout differs from the PDB");
