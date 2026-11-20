// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InstanceData; size 0x14
#pragma once
struct InstanceData {
    unsigned int id;
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned short rotZ;
    unsigned short scale;
    unsigned short alpha;
    bool hidden;
    unsigned char pad11;
    unsigned short pad12;
};
static_assert(sizeof(InstanceData) == 20, "InstanceData layout differs from the PDB");
