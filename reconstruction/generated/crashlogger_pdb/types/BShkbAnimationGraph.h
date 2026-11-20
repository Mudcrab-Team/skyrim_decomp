// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BShkbAnimationGraph; size 0x250
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSIRagdollDriver_ad6bead1.h"
#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "BSTArray_RE__BShkFloatController_727bd41c_dc045332.h"
#include "BSTArray_RE__BShkbAnimationGraph__BoneNodeEntry_c957732b_4231da57.h"
#include "BSTArray_unsigned_char_RE__BSTSmallArrayHeapAllocator_1_4a8dc8a5.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee_400203cc.h"
#include "BSTEventSource_RE__BSAnimationGraphEvent_ec52f639.h"
#include "BSTEventSource_RE__BSTransformDeltaEvent_f7efc871.h"
struct Actor;
struct BSFadeNode_d765e32e;
struct ID;
struct ProjectDBData_9c25c8ad;
struct bhkWorld;
struct hkbBehaviorGraph;
struct hkbGeneratorOutput;
struct BShkbAnimationGraph {
    BSIRagdollDriver_ad6bead1 _base;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    unsigned char undefined_c[4];
    BSTEventSource_RE__BSTransformDeltaEvent_f7efc871 _base_BSTEventSource_RE_BSTransformDeltaEvent_;
    BSTEventSource_RE__BSAnimationGraphEvent_ec52f639 _base_BSTEventSource_RE_BSAnimationGraphEvent_;
    unsigned char characterInstance_raw[160];
    BSTArray_RE__BShkbAnimationGraph__BoneNodeEntry_c957732b_4231da57 boneNodes;
    BSTArray_RE__BShkFloatController_727bd41c_dc045332 fadeControllers;
    BSTArray_void_9eb8914c_e1846db0 unk190;
    BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee_400203cc unk1A8;
    BSTArray_unsigned_char_RE__BSTSmallArrayHeapAllocator_1_4a8dc8a5 unk1C0;
    unsigned long long unk1D8;
    unsigned long long unk1E0;
    float interpolationTimeOffsets[2];
    BSFixedString_char_83b572b4 projectName;
    ID* unk1F8;
    ProjectDBData_9c25c8ad* projectDBData;
    hkbBehaviorGraph* behaviorGraph;
    Actor* holder;
    BSFadeNode_d765e32e* rootNode;
    hkbGeneratorOutput* generatorOutputs[2];
    float interpolationAmounts[2];
    bhkWorld* physicsWorld;
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
static_assert(sizeof(BShkbAnimationGraph) == 592, "BShkbAnimationGraph layout differs from the PDB");
