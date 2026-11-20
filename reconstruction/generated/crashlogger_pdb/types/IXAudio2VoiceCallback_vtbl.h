// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IXAudio2VoiceCallback_vtbl; size 0x38
#pragma once
struct IXAudio2VoiceCallback_vtbl {
    void (*OnVoiceProcessingPassStart)(unsigned int);
    void (*OnVoiceProcessingPassEnd)(void);
    void (*OnStreamEnd)(void);
    void (*OnBufferStart)(void* );
    void (*OnBufferEnd)(void* );
    void (*OnLoopEnd)(void* );
    void (*OnVoiceError)(void* , int);
};
static_assert(sizeof(IXAudio2VoiceCallback_vtbl) == 56, "IXAudio2VoiceCallback_vtbl layout differs from the PDB");
