// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IAnimationClipLoaderSingleton_vtbl; size 0x30
#pragma once
struct IAnimationClipLoaderSingleton_vtbl {
    void (*_dtor_IAnimationClipLoaderSingleton)(void);
    int (*Queue)(char32_t* , char32_t* , char32_t* );
    bool (*Load)(char32_t* );
    int (*Unload)(char32_t* , char32_t* , char32_t* );
    void (*Unk_04)(void);
    void (*Unk_05)(void);
};
static_assert(sizeof(IAnimationClipLoaderSingleton_vtbl) == 48, "IAnimationClipLoaderSingleton_vtbl layout differs from the PDB");
