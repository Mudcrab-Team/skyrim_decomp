// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxStateBag_vtbl; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "StateType.h"
struct GFxStateBag;
struct GFxState_6a94ada2;
struct GFxStateBag_vtbl_ba442c99 {
    GFxStateBag*(*GetStateBagImpl)(void);
    void (*_dtor_GFxStateBag)(void);
    void (*SetState)(StateType, GFxState_6a94ada2* );
    GFxState_6a94ada2*(*GetStateAddRef)(StateType);
    void (*GetStatesAddRef)(GFxState_6a94ada2** , StateType* , unsigned int);
};
static_assert(sizeof(GFxStateBag_vtbl_ba442c99) == 40, "GFxStateBag_vtbl_ba442c99 layout differs from the PDB");
