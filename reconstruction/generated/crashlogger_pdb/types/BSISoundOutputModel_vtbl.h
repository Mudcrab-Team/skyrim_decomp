// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSISoundOutputModel_vtbl; size 0x50
#pragma once
struct BSISoundOutputModel_vtbl {
    void (*_dtor_BSISoundOutputModel)(void);
    bool (*DoGetUsesHRTF)(void);
    bool (*DoGetHasSpeakerBias)(void);
    void (*DoGetSpeakerBias)(void);
    bool (*DoGetAttenuatesWithDistance)(void);
    bool (*DoGetAudibility)(float);
    unsigned int (*DoGetSupportedInputChannels)(void);
    char32_t*(*DoGetAttenuation)(void);
    float (*DoGetReverbSendLevel)(void);
    bool (*DoGetSupportsMonitor)(unsigned int);
};
static_assert(sizeof(BSISoundOutputModel_vtbl) == 80, "BSISoundOutputModel_vtbl layout differs from the PDB");
