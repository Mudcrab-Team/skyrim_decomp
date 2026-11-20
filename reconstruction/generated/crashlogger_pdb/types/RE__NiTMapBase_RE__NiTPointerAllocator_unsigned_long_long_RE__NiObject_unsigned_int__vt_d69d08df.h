// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RE::NiTMapBase<RE::NiTPointerAllocator<unsigned long long>, RE::NiObject *, unsigned int>_vtbl; size 0x38
#pragma once
struct RE__NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__NiObject_unsigned_int__vt_d69d08df {
    void (*_dtor_NiTMapBase)(void);
    unsigned int (*hash_function)(char32_t* );
    bool (*key_eq)(char32_t* , char32_t* );
    void (*assign_value)(char32_t* , char32_t* , char32_t* );
    void (*clear_value)(char32_t* );
    char32_t*(*malloc_value)(void);
    void (*free_value)(char32_t* );
};
static_assert(sizeof(RE__NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__NiObject_unsigned_int__vt_d69d08df) == 56, "RE__NiTMapBase_RE__NiTPointerAllocator_unsigned_long_long_RE__NiObject_unsigned_int__vt_d69d08df layout differs from the PDB");
