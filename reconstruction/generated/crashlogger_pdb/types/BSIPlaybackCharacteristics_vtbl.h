// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIPlaybackCharacteristics_vtbl; size 0x30
#pragma once
struct BSIPlaybackCharacteristics_vtbl {
    void (*_dtor_BSIPlaybackCharacteristics)(void);
    unsigned char (*GetFrequencyShift)(void);
    unsigned char (*GetFrequencyVariance)(void);
    unsigned char (*GetPriority)(void);
    unsigned short (*GetStaticAttenuation)(void);
    unsigned char (*GetDBVariance)(void);
};
static_assert(sizeof(BSIPlaybackCharacteristics_vtbl) == 48, "BSIPlaybackCharacteristics_vtbl layout differs from the PDB");
