// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbStateMachine; size 0x108
#pragma once

#include "EnumSet_RE__hkbStateMachine__StartStateMode_unsigned_char_a0aa9668.h"
#include "EnumSet_RE__hkbStateMachine__StateMachineSelfTransitionMode_unsigned_char_86311495.h"
#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkArray_RE__hkbStateMachine__StateInfo_a85d972f.h"
#include "hkRefPtr_RE__hkbStateChooser_d22c753f.h"
#include "hkRefPtr_RE__hkbStateMachine__TransitionInfoArray_178d3b8c.h"
#include "hkRefVariant_5e592efa.h"
#include "hkbEvent.h"
#include "hkbGenerator_a718bde7.h"
struct hkbStateMachine {
    hkbGenerator_a718bde7 _base;
    hkbEvent eventToSendWhenStateOrTransitionChanges;
    hkRefPtr_RE__hkbStateChooser_d22c753f startStateChooser;
    int startStateID;
    int returnToPreviousStateEventID;
    int randomTransitionEventID;
    int transitionToNextHigherStateEventID;
    int transitionToNextLowerStateEventID;
    int syncVariableIndex;
    int currentStateID;
    bool wrapAroundStateID;
    unsigned char maxSimultaneousTransitions;
    EnumSet_RE__hkbStateMachine__StartStateMode_unsigned_char_a0aa9668 startStateMode;
    EnumSet_RE__hkbStateMachine__StateMachineSelfTransitionMode_unsigned_char_86311495 selfTransitionMode;
    bool isActive;
    unsigned char pad41;
    unsigned short pad42;
    unsigned int pad44;
    hkArray_RE__hkbStateMachine__StateInfo_a85d972f states;
    hkRefPtr_RE__hkbStateMachine__TransitionInfoArray_178d3b8c wildcardTransitions;
    hkRefVariant_5e592efa stateIDToIndexMap;
    hkArray_RE__hkRefVariant_9938e2d5 activeTransitions;
    hkArray_RE__hkRefVariant_9938e2d5 transitionFlags;
    hkArray_RE__hkRefVariant_9938e2d5 wildcardTransitionFlags;
    hkArray_RE__hkRefVariant_9938e2d5 delayedTransitions;
    float timeInState;
    float lastLocalTime;
    int previousStateID;
    int nextStartStateIndexOverride;
    bool stateOrTransitionChanged;
    bool echoNextUpdate;
    unsigned short currentStateIndexAndEntered;
    unsigned int pad0BC;
};
static_assert(sizeof(hkbStateMachine) == 264, "hkbStateMachine layout differs from the PDB");
