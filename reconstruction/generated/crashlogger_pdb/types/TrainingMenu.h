// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TrainingMenu; size 0xf0
#pragma once

#include "ActorValue_a2156ae9.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct Actor_b2630b95;
struct TrainingMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    Actor_b2630b95* trainer;
    ActorValue_a2156ae9 skill;
    unsigned int unk44;
    GFxValue trainingMenuObj;
    GFxValue skillName;
    GFxValue skillMeter;
    GFxValue trainerSkill;
    GFxValue timesTrained;
    GFxValue trainCost;
    GFxValue currentGold;
};
static_assert(sizeof(TrainingMenu) == 240, "TrainingMenu layout differs from the PDB");
