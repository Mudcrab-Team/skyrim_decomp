// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveGameBuffer_vtbl; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

struct Actor_b2630b95;
struct TESForm;
struct TESObjectREFR_b225f218;
struct BGSSaveGameBuffer_vtbl_b5606b51 {
    void (*_dtor_BGSSaveGameBuffer)(void);
    TESForm*(*GetForm)(void);
    TESObjectREFR_b225f218*(*GetReference)(void);
    Actor_b2630b95*(*GetActor)(void);
};
static_assert(sizeof(BGSSaveGameBuffer_vtbl_b5606b51) == 32, "BGSSaveGameBuffer_vtbl_b5606b51 layout differs from the PDB");
