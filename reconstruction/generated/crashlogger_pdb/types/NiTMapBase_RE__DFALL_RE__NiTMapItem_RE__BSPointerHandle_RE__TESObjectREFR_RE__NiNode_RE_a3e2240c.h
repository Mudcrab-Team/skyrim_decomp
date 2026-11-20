// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTMapBase<RE::DFALL<RE::NiTMapItem<RE::BSPointerHandle<RE::TESObjectREFR>, RE::NiNode *>>, RE::BSPointerHandle<RE::TESObjectREFR>, RE::NiNode *>_vtbl; size 0x38
// one of 2 different PDB types sharing this name
#pragma once
struct NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_RE_a3e2240c {
    void (*_dtor_NiTMapBase)(void);
    unsigned int (*hash_function)(char32_t* );
    bool (*key_eq)(char32_t* , char32_t* );
    void (*assign_value)(char32_t* , char32_t* , char32_t* );
    void (*clear_value)(char32_t* );
    char32_t*(*malloc_value)(void);
    void (*free_value)(char32_t* );
};
static_assert(sizeof(NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_RE_a3e2240c) == 56, "NiTMapBase_RE__DFALL_RE__NiTMapItem_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_RE_a3e2240c layout differs from the PDB");
