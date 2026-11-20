// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HighActorCuller; size 0x150
#pragma once

#include "BSFadeNodeCuller.h"
#include "MobIterOperator.h"
#include "NiPointer_RE__BSMultiBoundNode_89b53a24.h"
#include "NiPointer_RE__BSMultiBoundSphere_ca5c8d11.h"
#include "NiPointer_RE__BSMultiBound_357f0b6a.h"
struct HighActorCuller {
    MobIterOperator _base;
    BSFadeNodeCuller culler;
    NiPointer_RE__BSMultiBoundNode_89b53a24 multiBoundNode;
    NiPointer_RE__BSMultiBound_357f0b6a multiBound;
    NiPointer_RE__BSMultiBoundSphere_ca5c8d11 multiBoundSphere;
};
static_assert(sizeof(HighActorCuller) == 336, "HighActorCuller layout differs from the PDB");
