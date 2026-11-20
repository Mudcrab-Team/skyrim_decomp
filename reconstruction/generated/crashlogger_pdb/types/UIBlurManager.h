// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UIBlurManager; size 0x20
#pragma once

#include "BSTEventSink_RE__DefaultObjectsReadyEvent__Event_774864cc.h"
#include "BSTSingletonSDM_RE__UIBlurManager_344a5158.h"
struct TESImageSpaceModifier;
struct UIBlurManager {
    BSTEventSink_RE__DefaultObjectsReadyEvent__Event_774864cc _base;
    BSTSingletonSDM_RE__UIBlurManager_344a5158 _base_BSTSingletonSDM_RE_UIBlurManager_;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
    TESImageSpaceModifier* blurEffect;
    unsigned short blurCount;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(UIBlurManager) == 32, "UIBlurManager layout differs from the PDB");
