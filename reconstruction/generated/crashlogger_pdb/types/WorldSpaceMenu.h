// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WorldSpaceMenu; size 0x48
#pragma once

#include "BSTEventSink_RE__HudModeChangeEvent_89984b26.h"
#include "IMenu_09c1ffe2.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct WorldSpaceMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__HudModeChangeEvent_89984b26 _base_BSTEventSink_RE_HudModeChangeEvent_;
    NiPointer_RE__NiNode_28171d5b menuNode;
    bool registerForHudModeChangeEvent;
    bool matchAsTopMenu;
    bool queueUpdateFixup;
    unsigned char pad53;
    unsigned int pad54;
};
static_assert(sizeof(WorldSpaceMenu) == 72, "WorldSpaceMenu layout differs from the PDB");
