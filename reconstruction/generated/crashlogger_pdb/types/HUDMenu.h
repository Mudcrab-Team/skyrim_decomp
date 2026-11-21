// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDMenu; size 0x98
#pragma once

#include "BSTArray_RE__HUDObject_78dc7418.h"
#include "BSTEventSink_RE__BSRemoteGamepadEvent_141aeb97.h"
#include "BSTEventSink_RE__UserEventEnabledEvent_9a5bd4f3.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct ActorValueMeter;
struct ShoutMeter;
struct HUDMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__UserEventEnabledEvent_9a5bd4f3 _base_BSTEventSink_RE_UserEventEnabledEvent_;
    BSTEventSink_RE__BSRemoteGamepadEvent_141aeb97 _base_BSTEventSink_RE_BSRemoteGamepadEvent_;
    BSTArray_RE__HUDObject_78dc7418 objects;
    ActorValueMeter* health;
    ActorValueMeter* stamina;
    ActorValueMeter* magicka;
    ShoutMeter* shout;
    GFxValue root;
    unsigned long long unk90;
};
static_assert(sizeof(HUDMenu) == 152, "HUDMenu layout differs from the PDB");
