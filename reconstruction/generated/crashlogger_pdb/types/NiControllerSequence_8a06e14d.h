// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiControllerSequence; size 0xb8
// one of 2 different PDB types sharing this name
#pragma once

#include "AnimState.h"
#include "BSFixedString_char_83b572b4.h"
#include "CycleType.h"
#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiStringPalette_5c3eb547.h"
#include "NiPointer_RE__NiTextKeyExtraData_c476872f.h"
#include "SimpleArray_RE__NiControllerSequence__IDTag_fc577dc4.h"
#include "SimpleArray_RE__NiControllerSequence__InterpArrayItem_ae559d89.h"
#include "SimpleArray_RE__NiPointer_RE__BSAnimNote_57383af1.h"
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence_8a06e14d {
    NiObject_de5bc370 _base;
    BSFixedString_char_83b572b4 name;
    unsigned int arraySize;
    unsigned int arrayGrowBy;
    SimpleArray_RE__NiControllerSequence__InterpArrayItem_ae559d89 interpArray;
    SimpleArray_RE__NiControllerSequence__IDTag_fc577dc4 idTagArray;
    float seqWeight;
    unsigned int pad34;
    NiPointer_RE__NiTextKeyExtraData_c476872f textKeys;
    CycleType cycleType;
    float frequency;
    float beginKeyTime;
    float endKeyTime;
    float lastTime;
    float weightedLastTime;
    float lastScaledTime;
    unsigned int pad5C;
    NiControllerManager* owner;
    AnimState state;
    float offset;
    float startTime;
    float endTime;
    float destFrame;
    unsigned int pad7C;
    NiControllerSequence_8a06e14d* partnerSequence;
    BSFixedString_char_83b572b4 accumRootName;
    NiAVObject* accumRoot;
    NiPointer_RE__NiStringPalette_5c3eb547 deprecatedStringPalette;
    short curAnimNIdx;
    unsigned short unkA2;
    unsigned int unkA4;
    SimpleArray_RE__NiPointer_RE__BSAnimNote_57383af1 animNotes;
    unsigned short numNotes;
    bool removableObjects;
    unsigned char unkB3;
    unsigned int unkB4;
};
static_assert(sizeof(NiControllerSequence_8a06e14d) == 184, "NiControllerSequence_8a06e14d layout differs from the PDB");
