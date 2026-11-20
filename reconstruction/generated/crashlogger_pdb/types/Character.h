// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Character; size 0x518
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Actor.h"
#include "NiPoint3_a7124070.h"
struct Character {
    Actor _base;
    unsigned char undefined_2b8[4];
    NiPoint3_a7124070 Position;
    char _middle[192];
    NiPoint3_a7124070 EditorLocPosition;
    char _tail[388];
};
static_assert(sizeof(Character) == 1304, "Character layout differs from the PDB");
