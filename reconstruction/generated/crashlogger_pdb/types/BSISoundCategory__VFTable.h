// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSISoundCategory__VFTable; size 0x60
#pragma once

struct BSISoundCategory_cbf1c4a4;
struct BSISoundCategory__VFTable {
    unsigned long long*(*dtor_0)(BSISoundCategory_cbf1c4a4* , char);
    int (*Matches_8)(void);
    int (*GetCategoryVolume_10)(void);
    int (*SetCategoryVolume_18)(void);
    int (*GetCategoryFrequency_20)(void);
    int (*SetCategoryFrequency_28)(void);
    int (*GetCategoryAttenuation_30)(void);
    int (*SetCategoryAttenuation_38)(void);
    int (*Func8_40)(void);
    int (*Func9_48)(void);
    int (*Func10_50)(void);
    int (*Func11_58)(void);
};
static_assert(sizeof(BSISoundCategory__VFTable) == 96, "BSISoundCategory__VFTable layout differs from the PDB");
