// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSISoundCategory_vtbl; size 0x60
#pragma once
struct BSISoundCategory_vtbl {
    void (*_dtor_BSISoundCategory)(void);
    bool (*Matches)(char32_t* );
    float (*GetCategoryVolume)(void);
    void (*SetCategoryVolume)(float);
    float (*GetCategoryFrequency)(void);
    void (*SetCategoryFrequency)(float);
    unsigned short (*GetCategoryAttenuation)(void);
    void (*SetCategoryAttenuation)(unsigned short);
    void (*Unk_08)(void);
    void (*Unk_09)(void);
    void (*Unk_0A)(void);
    void (*Unk_0B)(void);
};
static_assert(sizeof(BSISoundCategory_vtbl) == 96, "BSISoundCategory_vtbl layout differs from the PDB");
