// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTMapBase<RE::DFALL<RE::NiTMapItem<const char *, RE::Setting *>>, const char *, RE::Setting *>_vtbl; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

struct BSPointerHandle_RE__TESObjectREFR_017ae4a4;
struct NiPointer_RE__NiControllerSequence_87fc1ea3;
struct NiTMapBase_RE__DFALL_RE__NiTMapItem_const_char_RE__Setting_const_char_RE__Setting__vtbl_f99f98f4 {
    void (*_dtor_NiTMapBase)(void);
    unsigned int (*hash_function)(BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    bool (*key_eq)(BSPointerHandle_RE__TESObjectREFR_017ae4a4, BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    void (*assign_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* , BSPointerHandle_RE__TESObjectREFR_017ae4a4, BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    void (*clear_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* );
    NiPointer_RE__NiControllerSequence_87fc1ea3*(*malloc_value)(void);
    void (*free_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* );
};
static_assert(sizeof(NiTMapBase_RE__DFALL_RE__NiTMapItem_const_char_RE__Setting_const_char_RE__Setting__vtbl_f99f98f4) == 56, "NiTMapBase_RE__DFALL_RE__NiTMapItem_const_char_RE__Setting_const_char_RE__Setting__vtbl_f99f98f4 layout differs from the PDB");
