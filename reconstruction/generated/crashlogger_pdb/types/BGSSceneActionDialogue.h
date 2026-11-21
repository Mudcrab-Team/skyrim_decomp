// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneActionDialogue; size 0x40
#pragma once

#include "BGSSceneAction.h"
#include "EmotionType.h"
struct TESTopic_3cb1295e;
struct BGSSceneActionDialogue {
    BGSSceneAction _base;
    TESTopic_3cb1295e* topic;
    int headtrackActorID;
    float loopingMax;
    float loopingMin;
    unsigned int unk34;
    EmotionType emotionType;
    unsigned int emotionValue;
};
static_assert(sizeof(BGSSceneActionDialogue) == 64, "BGSSceneActionDialogue layout differs from the PDB");
