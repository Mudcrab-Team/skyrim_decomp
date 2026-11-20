// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MoviePlayer_vtbl; size 0x70
#pragma once
struct MoviePlayer_vtbl {
    void (*_dtor_MoviePlayer)(void);
    void (*MuteAudio)(void);
    void (*UnmuteAudio)(void);
    void (*PauseMusic)(void);
    void (*UnPauseMusic)(void);
    void (*SuspendAudioThread)(void);
    void (*ResumeAudioThread)(void);
    void (*LockRenderer)(void);
    void (*UnlockRenderer)(void);
    float (*GetScreenWidth)(void);
    float (*GetScreenHeight)(void);
    bool (*IsRendererInsideFrame)(void);
    unsigned long long (*GetMainThreadID)(void);
    void (*Unk_0D)(void);
};
static_assert(sizeof(MoviePlayer_vtbl) == 112, "MoviePlayer_vtbl layout differs from the PDB");
