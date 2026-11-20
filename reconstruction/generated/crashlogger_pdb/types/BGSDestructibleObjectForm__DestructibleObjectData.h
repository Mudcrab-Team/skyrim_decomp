// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDestructibleObjectForm__DestructibleObjectData; size 0x20
#pragma once

#include "NiPointer_QueuedFile_14ac7c8f.h"
struct BGSDestructibleObjectForm__DestructibleObjectStage;
struct BGSDestructibleObjectForm__DestructibleObjectData {
    int Health_0;
    char NumStages_4;
    unsigned char Flags_5;
    char _pad_6[2];
    BGSDestructibleObjectForm__DestructibleObjectStage** Stages_8;
    int ReplacementModelRefCount_10;
    char _pad_14[4];
    NiPointer_QueuedFile_14ac7c8f PreloadedReplacementModels_18;
};
static_assert(sizeof(BGSDestructibleObjectForm__DestructibleObjectData) == 32, "BGSDestructibleObjectForm__DestructibleObjectData layout differs from the PDB");
