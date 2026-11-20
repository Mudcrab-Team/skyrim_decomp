// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Color; size 0x4
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct Color {
    unsigned char Red_0;
    unsigned char Green_1;
    unsigned char Blue_2;
    unsigned char Alpha_3;
};
static_assert(sizeof(Color) == 4, "Color layout differs from the PDB");
