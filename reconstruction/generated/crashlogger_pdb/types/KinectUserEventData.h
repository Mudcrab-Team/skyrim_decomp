// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KinectUserEventData; size 0x20
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "IUIMessageData.h"
struct KinectUserEventData {
    IUIMessageData _base;
    BSFixedString_char_83b572b4 unk10;
    BSFixedString_char_83b572b4 unk18;
};
static_assert(sizeof(KinectUserEventData) == 32, "KinectUserEventData layout differs from the PDB");
