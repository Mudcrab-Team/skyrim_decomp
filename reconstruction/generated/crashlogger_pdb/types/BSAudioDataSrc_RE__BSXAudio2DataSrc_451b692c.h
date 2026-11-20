// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioDataSrc<RE::BSXAudio2DataSrc>; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
struct BSAudioDataSrc_vtbl;
struct StreamBase;
struct BSAudioDataSrc_RE__BSXAudio2DataSrc_451b692c {
    BSAudioDataSrc_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned int flags;
    StreamBase* stream;
};
static_assert(sizeof(BSAudioDataSrc_RE__BSXAudio2DataSrc_451b692c) == 24, "BSAudioDataSrc_RE__BSXAudio2DataSrc_451b692c layout differs from the PDB");
