// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Skills; size 0x30
#pragma once
struct Skills {
    unsigned char values[18];
    unsigned char offsets[18];
    unsigned short health;
    unsigned short magicka;
    unsigned short stamina;
    unsigned short pad2A;
    float farawayModelDistance;
};
static_assert(sizeof(Skills) == 48, "Skills layout differs from the PDB");
