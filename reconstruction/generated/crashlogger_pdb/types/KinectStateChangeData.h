// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KinectStateChangeData; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "IUIMessageData.h"
struct KinectStateChangeData {
    IUIMessageData _base;
    unsigned long long unk10;
    BSFixedString_char_83b572b4 unk18;
};
static_assert(sizeof(KinectStateChangeData) == 32, "KinectStateChangeData layout differs from the PDB");
