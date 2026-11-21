// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AMMO_DATA; size 0x10
#pragma once

struct BGSProjectile_dfe2d43e;
struct AMMO_DATA {
    BGSProjectile_dfe2d43e* projectile;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pa09;
    unsigned short pa0A;
    float damage;
};
static_assert(sizeof(AMMO_DATA) == 16, "AMMO_DATA layout differs from the PDB");
