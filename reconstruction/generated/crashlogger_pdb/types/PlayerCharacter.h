// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerCharacter; size 0xbf0
#pragma once

#include "BSTEventSink_RE__MenuModeChangeEvent_37ac473d.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "BSTEventSink_RE__TESTrackedStatsEvent_8b2284e2.h"
#include "BSTEventSink_RE__UserEventEnabledEvent_9a5bd4f3.h"
#include "BSTEventSource_RE__BGSActorCellEvent_266e4475.h"
#include "BSTEventSource_RE__BGSActorDeathEvent_6cdc140d.h"
#include "BSTEventSource_RE__PositionPlayerEvent_a5003311.h"
#include "Character_e6f5fd0a.h"
struct PlayerCharacter {
    Character_e6f5fd0a _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    BSTEventSink_RE__MenuModeChangeEvent_37ac473d _base_BSTEventSink_RE_MenuModeChangeEvent_;
    BSTEventSink_RE__UserEventEnabledEvent_9a5bd4f3 _base_BSTEventSink_RE_UserEventEnabledEvent_;
    BSTEventSink_RE__TESTrackedStatsEvent_8b2284e2 _base_BSTEventSink_RE_TESTrackedStatsEvent_;
    BSTEventSource_RE__BGSActorCellEvent_266e4475 _base_BSTEventSource_RE_BGSActorCellEvent_;
    BSTEventSource_RE__BGSActorDeathEvent_6cdc140d _base_BSTEventSource_RE_BGSActorDeathEvent_;
    BSTEventSource_RE__PositionPlayerEvent_a5003311 _base_BSTEventSource_RE_PositionPlayerEvent_;
    unsigned char _padPlayerRuntimeData[2056];
    unsigned char undefined_be8[8];
};
static_assert(sizeof(PlayerCharacter) == 3056, "PlayerCharacter layout differs from the PDB");
