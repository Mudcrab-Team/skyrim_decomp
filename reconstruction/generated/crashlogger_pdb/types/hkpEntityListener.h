// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntityListener; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpEntityListener_vtbl;
struct hkpEntityListener {
    hkpEntityListener_vtbl* __vftable;
};
static_assert(sizeof(hkpEntityListener) == 8, "hkpEntityListener layout differs from the PDB");
