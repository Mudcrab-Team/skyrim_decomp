// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPathingCell_vtbl; size 0x58
// one of 2 different PDB types sharing this name
#pragma once

#include "ErrorCode_092d7eaa.h"
#include "FunctorType.h"
struct BSPathingNumericIDVisitor_811608a7;
struct BSTSmartPointer_RE__BSPathingCell_9e2f1f4e;
struct bhkWorld_a655538a;
struct BSPathingCell_vtbl_a4737d47 {
    void (*_dtor_BSPathingCell)(void);
    FunctorType (*GetType)(void);
    ErrorCode_092d7eaa (*Write)(unsigned long long, unsigned char* );
    ErrorCode_092d7eaa (*Read)(unsigned long long, unsigned char* );
    void (*FixupNumericID)(BSPathingNumericIDVisitor_811608a7* );
    void (*GetSpace)(char32_t* );
    bhkWorld_a655538a*(*GetBhkWorld)(void);
    bool (*QValid)(void);
    bool (*QAttached)(void);
    bool (*QLoaded)(void);
    bool (*IsInSameSpace)(BSTSmartPointer_RE__BSPathingCell_9e2f1f4e* );
};
static_assert(sizeof(BSPathingCell_vtbl_a4737d47) == 88, "BSPathingCell_vtbl_a4737d47 layout differs from the PDB");
