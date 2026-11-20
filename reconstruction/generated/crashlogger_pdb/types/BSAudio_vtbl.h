// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudio_vtbl; size 0x58
#pragma once
struct BSAudio_vtbl {
    void (*_dtor_BSAudio)(void);
    void (*Init)(char32_t* );
    void (*Shutdown)(void);
    char32_t*(*GetGameSound)(char32_t* );
    void (*ReleaseGameSound)(char32_t* );
    char32_t*(*GetSystemName)(void);
    void (*PostGameSoundUpdates)(void);
    void (*ApplyReverbType)(char32_t* , unsigned int);
    unsigned int (*CreateMonitor)(void);
    void (*ReleaseMonitor)(unsigned int);
    void (*GetReceiver)(unsigned int);
};
static_assert(sizeof(BSAudio_vtbl) == 88, "BSAudio_vtbl layout differs from the PDB");
