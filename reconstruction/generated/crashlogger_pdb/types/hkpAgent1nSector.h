// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgent1nSector; size 0x200
#pragma once
struct hkpAgent1nSector {
    unsigned int bytesAllocated;
    unsigned int pad04;
    unsigned int pad08;
    unsigned int pad0C;
    unsigned char data[496];
};
static_assert(sizeof(hkpAgent1nSector) == 512, "hkpAgent1nSector layout differs from the PDB");
