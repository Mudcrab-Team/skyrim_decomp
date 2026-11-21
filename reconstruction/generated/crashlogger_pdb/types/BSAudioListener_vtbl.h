// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioListener_vtbl; size 0x30
#pragma once
struct BSAudioListener_vtbl {
    void (*_dtor_BSAudioListener)(void);
    void (*Unk_01)(void);
    void (*Unk_02)(void);
    void (*Unk_03)(void);
    void (*Unk_04)(void);
    void (*Unk_05)(void);
};
static_assert(sizeof(BSAudioListener_vtbl) == 48, "BSAudioListener_vtbl layout differs from the PDB");
