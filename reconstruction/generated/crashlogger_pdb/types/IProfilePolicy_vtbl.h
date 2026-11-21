// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IProfilePolicy_vtbl; size 0x28
#pragma once
struct IProfilePolicy_vtbl {
    void (*_dtor_IProfilePolicy)(void);
    void (*StackFramePushQueued)(unsigned int, unsigned int, char32_t* );
    void (*StackFramePushed)(unsigned int, unsigned int, char32_t* , char32_t* , char32_t* , char32_t* );
    void (*StackFramePopQueued)(unsigned int, unsigned int, char32_t* , char32_t* , char32_t* , char32_t* );
    void (*StackFramePopped)(unsigned int, unsigned int, char32_t* , char32_t* , char32_t* , char32_t* );
};
static_assert(sizeof(IProfilePolicy_vtbl) == 40, "IProfilePolicy_vtbl layout differs from the PDB");
