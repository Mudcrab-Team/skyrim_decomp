// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIAttenuationCharacteristics_vtbl; size 0x20
#pragma once
struct BSIAttenuationCharacteristics_vtbl {
    void (*_dtor_BSIAttenuationCharacteristics)(void);
    float (*GetMaxDistance)(void);
    float (*GetMinDistance)(void);
    unsigned char (*GetCurveValue)(unsigned int);
};
static_assert(sizeof(BSIAttenuationCharacteristics_vtbl) == 32, "BSIAttenuationCharacteristics_vtbl layout differs from the PDB");
