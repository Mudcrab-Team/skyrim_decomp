// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LEVELED_OBJECT; size 0x18
#pragma once

struct ContainerItemExtra;
struct TESForm;
struct LEVELED_OBJECT {
    TESForm* form;
    unsigned short count;
    unsigned short level;
    unsigned int pad0C;
    ContainerItemExtra* itemExtra;
};
static_assert(sizeof(LEVELED_OBJECT) == 24, "LEVELED_OBJECT layout differs from the PDB");
