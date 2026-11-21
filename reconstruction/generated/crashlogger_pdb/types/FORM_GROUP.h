// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FORM_GROUP; size 0x20
#pragma once

#include "FORM.h"
struct FORM_GROUP {
    FORM groupData;
    unsigned long long groupOffset;
};
static_assert(sizeof(FORM_GROUP) == 32, "FORM_GROUP layout differs from the PDB");
