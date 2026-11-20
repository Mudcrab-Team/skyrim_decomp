// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESAIForm; size 0x28
#pragma once

#include "BaseFormComponent.h"
#include "PackageList.h"
struct TESAIForm {
    BaseFormComponent _base;
    unsigned char aiData_raw[16];
    PackageList aiPackages;
};
static_assert(sizeof(TESAIForm) == 40, "TESAIForm layout differs from the PDB");
