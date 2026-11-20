// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IListener_vtbl; size 0x20
#pragma once
struct IListener_vtbl {
    void (*_dtor_IListener)(void);
    void (*OnKeyDown)(char32_t* , int, unsigned char, unsigned int, unsigned char);
    void (*OnKeyUp)(char32_t* , int, unsigned char, unsigned int, unsigned char);
    void (*Update)(char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(IListener_vtbl) == 32, "IListener_vtbl layout differs from the PDB");
