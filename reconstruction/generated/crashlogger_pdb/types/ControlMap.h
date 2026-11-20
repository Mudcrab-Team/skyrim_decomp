// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ControlMap; size 0x130
#pragma once

#include "BSTArray_RE__ControlMap__LinkedMapping_71cc7a50.h"
#include "BSTArray_RE__UserEvents__INPUT_CONTEXT_IDS__INPUT_CONTEXT_ID_d7e4e5ec.h"
#include "BSTEventSource_RE__UserEventEnabled_9c655786.h"
#include "BSTSingletonSDM_RE__ControlMap_71b30b25.h"
#include "PC_GAMEPAD_TYPE.h"
#include "USER_EVENT_FLAG.h"
struct InputContext;
struct ControlMap {
    BSTSingletonSDM_RE__ControlMap_71b30b25 _base;
    unsigned char undefined_1[7];
    BSTEventSource_RE__UserEventEnabled_9c655786 _base_BSTEventSource_RE_UserEventEnabled_;
    InputContext* controlMap[18];
    BSTArray_RE__ControlMap__LinkedMapping_71cc7a50 linkedMappings;
    BSTArray_RE__UserEvents__INPUT_CONTEXT_IDS__INPUT_CONTEXT_ID_d7e4e5ec contextPriorityStack;
    USER_EVENT_FLAG enabledControls;
    USER_EVENT_FLAG storedControls;
    unsigned char textEntryCount;
    bool ignoreKeyboardMouse;
    bool ignoreActivateDisabledEvents;
    unsigned char pad123;
    PC_GAMEPAD_TYPE gamePadMapType;
};
static_assert(sizeof(ControlMap) == 304, "ControlMap layout differs from the PDB");
