// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapCamera; size 0x90
#pragma once

#include "BSTPoint2_float_af46c5cb.h"
#include "BSTPoint3_float_ba0b407f.h"
#include "BSTSmartPointer_RE__MapCameraStates__Exit_912416b4.h"
#include "BSTSmartPointer_RE__MapCameraStates__Transition_b2b8db54.h"
#include "TESCamera.h"
struct IMapCameraCallbacks;
struct TESWorldSpace;
struct MapCamera {
    TESCamera _base;
    BSTPoint2_float_af46c5cb unk38;
    BSTPoint3_float_ba0b407f unk40;
    unsigned int unk4C;
    TESWorldSpace* worldSpace;
    IMapCameraCallbacks* unk58;
    unsigned int unk60;
    unsigned int unk64;
    unsigned char unk68_raw[16];
    BSTSmartPointer_RE__MapCameraStates__Exit_912416b4 unk78;
    BSTSmartPointer_RE__MapCameraStates__Transition_b2b8db54 unk80;
    unsigned char unk88;
    unsigned char pad89;
    unsigned short pad8A;
    unsigned int pad8C;
};
static_assert(sizeof(MapCamera) == 144, "MapCamera layout differs from the PDB");
