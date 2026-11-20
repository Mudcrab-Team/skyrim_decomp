// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatBehaviorTreeNode_vtbl; size 0x50
#pragma once

#include "hkpPhantomType.h"
struct CombatBehaviorTreeNode_vtbl {
    void (*_dtor_CombatBehaviorTreeNode)(void);
    void (*GetName)(void);
    void (*Enter)(char32_t* );
    void (*Exit)(char32_t* );
    void (*Update)(char32_t* , char32_t* , char32_t* );
    void (*Abort)(char32_t* );
    void (*SaveGame)(char32_t* );
    void (*LoadGame)(char32_t* );
    bool (*Validate)(void);
    hkpPhantomType (*GetType)(void);
};
static_assert(sizeof(CombatBehaviorTreeNode_vtbl) == 80, "CombatBehaviorTreeNode_vtbl layout differs from the PDB");
