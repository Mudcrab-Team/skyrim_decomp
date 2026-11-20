// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxStateBag_vtbl; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "StateType.h"
struct GFxStateBag_vtbl {
    char32_t*(*GetStateBagImpl)(void);
    void (*_dtor_GFxStateBag)(void);
    void (*SetState)(StateType, char32_t* );
    char32_t*(*GetStateAddRef)(StateType);
    void (*GetStatesAddRef)(char32_t** , StateType* , unsigned int);
};
static_assert(sizeof(GFxStateBag_vtbl) == 40, "GFxStateBag_vtbl layout differs from the PDB");
