// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BShkbAnimationGraph; size 0x250
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSIRagdollDriver.h"
#include "BSIntrusiveRefCounted.h"
#include "BSTArray_RE__BShkFloatController_727bd41c.h"
#include "BSTArray_RE__BShkbAnimationGraph__BoneNodeEntry_c957732b.h"
#include "BSTArray_unsigned_char_RE__BSTSmallArrayHeapAllocator_1_4a8dc8a5_d93980c9.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee.h"
#include "BSTEventSource_RE__BSAnimationGraphEvent_ec52f639_fb4610c0.h"
#include "BSTEventSource_RE__BSTransformDeltaEvent_f7efc871_fb0d4b41.h"
#include "hkbCharacter_b1920be0.h"
struct Actor_b2630b95;
struct BSFadeNode;
struct ID;
struct ProjectDBData;
struct bhkWorld_a655538a;
struct hkbBehaviorGraph_55faab91;
struct hkbGeneratorOutput;
struct BShkbAnimationGraph_f98faf6c {
    BSIRagdollDriver _base;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    BSTEventSource_RE__BSTransformDeltaEvent_f7efc871_fb0d4b41 _base_BSTEventSource_RE_BSTransformDeltaEvent_;
    BSTEventSource_RE__BSAnimationGraphEvent_ec52f639_fb4610c0 _base_BSTEventSource_RE_BSAnimationGraphEvent_;
    hkbCharacter_b1920be0 characterInstance;
    BSTArray_RE__BShkbAnimationGraph__BoneNodeEntry_c957732b boneNodes;
    BSTArray_RE__BShkFloatController_727bd41c fadeControllers;
    BSTArray_void_9eb8914c unk190;
    BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee unk1A8;
    BSTArray_unsigned_char_RE__BSTSmallArrayHeapAllocator_1_4a8dc8a5_d93980c9 unk1C0;
    unsigned long long unk1D8;
    unsigned long long unk1E0;
    float interpolationTimeOffsets[2];
    BSFixedString_char_83b572b4 projectName;
    ID* unk1F8;
    ProjectDBData* projectDBData;
    hkbBehaviorGraph_55faab91* behaviorGraph;
    Actor_b2630b95* holder;
    BSFadeNode* rootNode;
    hkbGeneratorOutput* generatorOutputs[2];
    float interpolationAmounts[2];
    bhkWorld_a655538a* physicsWorld;
    unsigned short numAnimBones;
    unsigned char unk242;
    unsigned char unk243;
    unsigned short unk244;
    unsigned char unk246;
    unsigned char unk247;
    unsigned char unk248;
    unsigned char doFootIK;
    unsigned short unk24A;
    unsigned int unk24C;
};
static_assert(sizeof(BShkbAnimationGraph_f98faf6c) == 592, "BShkbAnimationGraph_f98faf6c layout differs from the PDB");
