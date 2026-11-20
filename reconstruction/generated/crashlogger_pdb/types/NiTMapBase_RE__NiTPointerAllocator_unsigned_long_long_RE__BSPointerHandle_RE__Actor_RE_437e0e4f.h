// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiTMapBase<RE::NiTPointerAllocator<unsigned long long>, RE::BSPointerHandle<RE::Actor>, RE::WadingWaterData *>_vtbl; size 0x38
#pragma once
struct NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__BSPointerHandle_RE__Actor_RE_437e0e4f {
    void (*_dtor_NiTMapBase)(void);
    unsigned int (*hash_function)(char32_t* );
    bool (*key_eq)(char32_t* , char32_t* );
    void (*assign_value)(char32_t* , char32_t* , char32_t* );
    void (*clear_value)(char32_t* );
    char32_t*(*malloc_value)(void);
    void (*free_value)(char32_t* );
};
static_assert(sizeof(NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__BSPointerHandle_RE__Actor_RE_437e0e4f) == 56, "NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__BSPointerHandle_RE__Actor_RE_437e0e4f layout differs from the PDB");
