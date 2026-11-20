// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KinectMenu; size 0x50
#pragma once

#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct KinectMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    GFxValue root;
};
static_assert(sizeof(KinectMenu) == 80, "KinectMenu layout differs from the PDB");
