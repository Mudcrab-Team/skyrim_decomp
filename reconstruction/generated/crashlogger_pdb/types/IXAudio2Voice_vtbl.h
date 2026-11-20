// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IXAudio2Voice_vtbl; size 0x98
#pragma once
struct IXAudio2Voice_vtbl {
    void (*GetVoiceDetails)(char32_t* );
    int (*SetOutputVoices)(char32_t* );
    int (*SetEffectChain)(char32_t* );
    int (*EnableEffect)(unsigned int, unsigned int);
    int (*DisableEffect)(unsigned int, unsigned int);
    void (*GetEffectState)(unsigned int, char32_t* );
    int (*SetEffectParameters)(unsigned int, void* , unsigned int, unsigned int);
    int (*GetEffectParameters)(unsigned int, void* , unsigned int);
    int (*SetFilterParameters)(char32_t* , unsigned int);
    void (*GetFilterParameters)(char32_t* );
    int (*SetOutputFilterParameters)(char32_t* , char32_t* , unsigned int);
    void (*GetOutputFilterParameters)(char32_t* , char32_t* );
    int (*SetVolume)(float, unsigned int);
    void (*GetVolume)(float* );
    int (*SetChannelVolumes)(unsigned int, float* , unsigned int);
    void (*GetChannelVolumes)(unsigned int, float* );
    int (*SetOutputMatrix)(char32_t* , unsigned int, unsigned int, float* , unsigned int);
    void (*GetOutputMatrix)(char32_t* , unsigned int, unsigned int, float* );
    void (*DestroyVoice)(void);
};
static_assert(sizeof(IXAudio2Voice_vtbl) == 152, "IXAudio2Voice_vtbl layout differs from the PDB");
