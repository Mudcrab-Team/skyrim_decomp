// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RaceSexMenu; size 0x1b8
#pragma once

#include "BSTArray_RE__BGSHeadPart_e1306f84.h"
#include "BSTArray_RaceComponent_cc93a6df.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "EnumSet_RE__SEXES__SEX_unsigned_int_36523908.h"
#include "IMenu.h"
#include "MenuEventHandler_95ed2a85.h"
#include "RaceSexCamera.h"
struct RaceSexMenu {
    IMenu _base;
    MenuEventHandler_95ed2a85 _base_MenuEventHandler;
    BSTArray_RE__BGSHeadPart_e1306f84 headParts[7];
    RaceSexCamera camera;
    BSTArray_RaceComponent_cc93a6df sliderData[2];
    BSTArray_void_9eb8914c_e1846db0 unk170;
    unsigned long long unk188;
    unsigned int unk190;
    unsigned int unk194;
    EnumSet_RE__SEXES__SEX_unsigned_int_36523908 sex;
    unsigned short unk19C;
    unsigned char unk19E;
    unsigned char pad19F;
    unsigned char unk1A0;
    unsigned char unk1A1;
    unsigned short unk1A2;
    unsigned int unk1A4;
};
static_assert(sizeof(RaceSexMenu) == 440, "RaceSexMenu layout differs from the PDB");
