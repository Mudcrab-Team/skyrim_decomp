// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTEventSource<RE::TESObjectREFRTranslationEvent>; size 0x58
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTEventSink_RE__TESObjectREFRTranslationEvent_a8be2f51.h"
struct BSTEventSource_RE__TESObjectREFRTranslationEvent_739660fe {
    BSTArray_RE__BSTEventSink_RE__TESObjectREFRTranslationEvent_a8be2f51 sinks;
    BSTArray_RE__BSTEventSink_RE__TESObjectREFRTranslationEvent_a8be2f51 pendingRegisters;
    BSTArray_RE__BSTEventSink_RE__TESObjectREFRTranslationEvent_a8be2f51 pendingUnregisters;
    BSSpinLock lock;
    bool notifying;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(BSTEventSource_RE__TESObjectREFRTranslationEvent_739660fe) == 88, "BSTEventSource_RE__TESObjectREFRTranslationEvent_739660fe layout differs from the PDB");
