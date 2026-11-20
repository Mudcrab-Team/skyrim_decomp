// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KinectEvent; size 0x30
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "IDEvent.h"
struct KinectEvent {
    IDEvent _base;
    BSFixedString_char_83b572b4 heard;
};
static_assert(sizeof(KinectEvent) == 48, "KinectEvent layout differs from the PDB");
