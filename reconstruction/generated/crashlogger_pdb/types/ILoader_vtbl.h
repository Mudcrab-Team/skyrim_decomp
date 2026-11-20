// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ILoader_vtbl; size 0x20
#pragma once
struct ILoader_vtbl {
    void (*_dtor_ILoader)(void);
    char32_t*(*Clone)(void);
    void (*SetScriptStore)(char32_t* );
    bool (*GetClass)(unsigned char* , char32_t* );
};
static_assert(sizeof(ILoader_vtbl) == 32, "ILoader_vtbl layout differs from the PDB");
