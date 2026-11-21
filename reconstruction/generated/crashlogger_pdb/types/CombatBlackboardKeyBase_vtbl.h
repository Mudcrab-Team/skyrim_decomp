// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBlackboardKeyBase_vtbl; size 0x38
#pragma once
struct CombatBlackboardKeyBase_vtbl {
    void (*_dtor_CombatBlackboardKeyBase)(void);
    unsigned int (*GetObjectSize)(void);
    void (*CreateObject)(char32_t* , unsigned char* , char32_t* , unsigned int);
    void (*DestroyObject)(void* );
    void (*GetName)(void);
    void (*SaveObject)(char32_t* , void* );
    bool (*LoadObject)(void);
};
static_assert(sizeof(CombatBlackboardKeyBase_vtbl) == 56, "CombatBlackboardKeyBase_vtbl layout differs from the PDB");
