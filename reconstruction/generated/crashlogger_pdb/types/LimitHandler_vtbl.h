// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LimitHandler_vtbl; size 0x18
#pragma once
struct LimitHandler_vtbl {
    void (*_dtor_LimitHandler)(void);
    bool (*OnExceedLimit)(char32_t* , char32_t* );
    void (*OnFreeSegment)(char32_t* , char32_t* );
};
static_assert(sizeof(LimitHandler_vtbl) == 24, "LimitHandler_vtbl layout differs from the PDB");
