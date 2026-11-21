// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudio; size 0x18
#pragma once

struct BSAudioListener;
struct BSAudio_vtbl;
struct BSAudio {
    BSAudio_vtbl* __vftable;
    unsigned long long unk08;
    BSAudioListener* audioListener;
};
static_assert(sizeof(BSAudio) == 24, "BSAudio layout differs from the PDB");
