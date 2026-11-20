// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTMapBase<RE::DFALL<RE::NiTMapItem<RE::TESForm *, RE::BSPointerHandle<RE::TESObjectREFR>>>, RE::TESForm *, RE::BSPointerHandle<RE::TESObjectREFR>>_vtbl; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSPointerHandle_RE__TESObjectREFR_017ae4a4;
struct NiPointer_RE__NiControllerSequence_87fc1ea3;
struct NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_R_e48d124f {
    void (*_dtor_NiTMapBase)(void);
    unsigned int (*hash_function)(BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    bool (*key_eq)(BSPointerHandle_RE__TESObjectREFR_017ae4a4, BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    void (*assign_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* , BSPointerHandle_RE__TESObjectREFR_017ae4a4, BSPointerHandle_RE__TESObjectREFR_017ae4a4);
    void (*clear_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* );
    NiPointer_RE__NiControllerSequence_87fc1ea3*(*malloc_value)(void);
    void (*free_value)(NiPointer_RE__NiControllerSequence_87fc1ea3* );
};
static_assert(sizeof(NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_R_e48d124f) == 56, "NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_R_e48d124f layout differs from the PDB");
