// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIReverbType_vtbl; size 0x58
#pragma once
struct BSIReverbType_vtbl {
    int (*DoGetRoomLevel)(void);
    int (*DoGetRoomHFLevel)(void);
    float (*DoGetDecayTime)(void);
    float (*DoGetDecayHFRatio)(void);
    int (*DoGetReflectionLevel)(void);
    float (*DoGetReflectionDelay)(void);
    int (*DoGetReverbLevel)(void);
    float (*DoGetReverbDelay)(void);
    float (*DoGetDiffusion)(void);
    float (*DoGetDensity)(void);
    float (*DoGetHFReference)(void);
};
static_assert(sizeof(BSIReverbType_vtbl) == 88, "BSIReverbType_vtbl layout differs from the PDB");
