// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadingMenu; size 0x80
#pragma once

#include "BSTArray_RE__TESLoadScreen_2cbf8e37.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct BGSLocation;
struct TESLoadScreen;
struct LoadingMenu {
    IMenu_09c1ffe2 _base;
    GFxValue root;
    BGSLocation* currentLocation;
    bool unk50;
    bool unk51;
    unsigned short pad52;
    unsigned int pad54;
    BSTArray_RE__TESLoadScreen_2cbf8e37 loadScreens;
    unsigned int unk70;
    unsigned int pad74;
    TESLoadScreen* loadScreen;
};
static_assert(sizeof(LoadingMenu) == 128, "LoadingMenu layout differs from the PDB");
