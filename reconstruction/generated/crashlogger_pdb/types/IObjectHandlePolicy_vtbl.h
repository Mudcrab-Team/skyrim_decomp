// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IObjectHandlePolicy_vtbl; size 0x60
#pragma once
struct IObjectHandlePolicy_vtbl {
    void (*_dtor_IObjectHandlePolicy)(void);
    bool (*HandleIsType)(char32_t* , char32_t* );
    bool (*IsHandleObjectAvailable)(char32_t* );
    void (*EmptyHandle)(void);
    void (*GetHandleForObject)(char32_t* , void* );
    bool (*HasParent)(char32_t* );
    void (*GetParentHandle)(char32_t* );
    void (*GetHandleScriptsMovedFrom)(char32_t* );
    void*(*GetObjectForHandle)(char32_t* , char32_t* );
    void (*PersistHandle)(char32_t* );
    void (*ReleaseHandle)(char32_t* );
    void (*ConvertHandleToString)(char32_t* , char32_t* );
};
static_assert(sizeof(IObjectHandlePolicy_vtbl) == 96, "IObjectHandlePolicy_vtbl layout differs from the PDB");
