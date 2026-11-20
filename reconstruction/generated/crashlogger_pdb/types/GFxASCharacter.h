// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxASCharacter; size 0x110
#pragma once

#include "GASObjectInterface.h"
#include "GFxCharacter.h"
struct GFxMovieDef;
struct GFxASCharacter {
    GFxCharacter _base;
    GASObjectInterface _base_GASObjectInterface;
    unsigned long long unk0B0;
    unsigned long long unk0B8;
    unsigned long long unk0C0;
    GFxMovieDef* movieDef;
    unsigned long long unk0D0;
    unsigned long long unk0D8;
    unsigned long long unk0E0;
    unsigned long long unk0E8;
    unsigned long long unk0F0;
    unsigned long long unk0F8;
    unsigned long long unk100;
    unsigned long long unk118;
};
static_assert(sizeof(GFxASCharacter) == 272, "GFxASCharacter layout differs from the PDB");
