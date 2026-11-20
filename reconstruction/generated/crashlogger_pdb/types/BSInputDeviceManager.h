// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSInputDeviceManager; size 0xf0
#pragma once

#include "BSTEventSource_RE__BSRemoteGamepadEvent_1b9bc0e6.h"
#include "BSTEventSource_RE__InputEvent_18931957.h"
#include "BSTSingletonSDM_RE__BSInputDeviceManager_cec89401.h"
struct BSIInputDevice;
struct BSInputDeviceManager {
    BSTEventSource_RE__InputEvent_18931957 _base;
    BSTSingletonSDM_RE__BSInputDeviceManager_cec89401 _base_BSTSingletonSDM_RE_BSInputDeviceManager_;
    unsigned char pad59;
    unsigned short pad5A;
    unsigned int pad5C;
    BSIInputDevice* devices[4];
    bool queuedGamepadEnableValue;
    bool valueQueued;
    bool pollingEnabled;
    unsigned char pad03;
    unsigned int pad04;
    BSTEventSource_RE__BSRemoteGamepadEvent_1b9bc0e6 remoteGamepadEventSource;
    unsigned char unk60;
    unsigned char unk61;
    unsigned short unk62;
    unsigned int unk64;
    unsigned long long unk68;
};
static_assert(sizeof(BSInputDeviceManager) == 240, "BSInputDeviceManager layout differs from the PDB");
