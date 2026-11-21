// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSGamepadDevice; size 0xd0
#pragma once

#include "BSInputDevice.h"
#include "BSTEventSource_RE__BSGamepadEvent_9cb27daf.h"
struct BSGamepadDevice {
    BSInputDevice _base;
    BSTEventSource_RE__BSGamepadEvent_9cb27daf _base_BSTEventSource_RE_BSGamepadEvent_;
    int userIndex;
    bool connected;
    bool listeningForInput;
    unsigned short padCE;
};
static_assert(sizeof(BSGamepadDevice) == 208, "BSGamepadDevice layout differs from the PDB");
