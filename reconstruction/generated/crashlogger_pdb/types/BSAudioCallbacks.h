// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioCallbacks; size 0x18
#pragma once
struct BSAudioCallbacks {
    unsigned char numericIDCallback_raw[8];
    unsigned char nameIDCallback_raw[8];
    unsigned char unk50_raw[8];
};
static_assert(sizeof(BSAudioCallbacks) == 24, "BSAudioCallbacks layout differs from the PDB");
