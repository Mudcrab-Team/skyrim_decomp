// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioListener; size 0x40
#pragma once

#include "NiPoint3.h"
struct BSAudioListener_vtbl;
struct BSAudioListener {
    BSAudioListener_vtbl* __vftable;
    NiPoint3 listenerPosition;
    unsigned int unk14;
    unsigned long long unk18;
    unsigned long long unk20;
    unsigned long long unk28;
    unsigned long long unk30;
    unsigned long long unk38;
};
static_assert(sizeof(BSAudioListener) == 64, "BSAudioListener layout differs from the PDB");
