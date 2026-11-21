// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbContext; size 0x50
#pragma once

#include "hkRefPtr_RE__hkbGeneratorOutputListener_93eb3e9a.h"
#include "hkRefVariant.h"
struct hkaDefaultAnimationControlMapperData_ba8c0a01;
struct hkbAttachmentManager;
struct hkbBehaviorGraph_55faab91;
struct hkbCharacter_b1920be0;
struct hkbEventQueue;
struct hkbContext {
    hkbCharacter_b1920be0* character;
    hkbBehaviorGraph_55faab91* behavior;
    hkRefVariant nodeToIndexMap;
    hkbEventQueue* eventQueue;
    hkaDefaultAnimationControlMapperData_ba8c0a01* sharedEventQueue;
    hkRefPtr_RE__hkbGeneratorOutputListener_93eb3e9a generatorOutputListener;
    bool eventTriggeredTransition;
    unsigned char pad31[7];
    hkRefVariant world;
    hkbAttachmentManager* attachmentManager;
    hkRefVariant animationCache;
};
static_assert(sizeof(hkbContext) == 80, "hkbContext layout differs from the PDB");
