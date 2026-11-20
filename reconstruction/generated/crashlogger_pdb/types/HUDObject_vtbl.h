// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDObject_vtbl; size 0x28
#pragma once

#include "UI_MESSAGE_RESULTS.h"
struct HUDObject_vtbl {
    void (*_dtor_HUDObject)(void);
    void (*Update)(char32_t* , char32_t* , char32_t* );
    UI_MESSAGE_RESULTS (*ProcessMessage)(char32_t* );
    void (*RegisterHUDComponent)(char32_t* );
    void (*CleanUp)(void);
};
static_assert(sizeof(HUDObject_vtbl) == 40, "HUDObject_vtbl layout differs from the PDB");
