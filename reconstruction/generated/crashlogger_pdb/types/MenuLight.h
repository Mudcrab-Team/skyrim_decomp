// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuLight; size 0x38
#pragma once

#include "NiColor_e5e1ad7d.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSLight_c51dfae1.h"
struct MenuLight {
    NiColor_e5e1ad7d color;
    NiPoint3 translate;
    float radius;
    float fade;
    bool castsShadows;
    unsigned char undefined_21[7];
    NiPointer_RE__BSLight_c51dfae1 light;
    MenuLight* last;
};
static_assert(sizeof(MenuLight) == 56, "MenuLight layout differs from the PDB");
