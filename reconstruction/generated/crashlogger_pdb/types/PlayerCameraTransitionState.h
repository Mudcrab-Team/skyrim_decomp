// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerCameraTransitionState; size 0x40
#pragma once

#include "TESCameraState.h"
struct PlayerCameraTransitionState {
    TESCameraState _base;
    unsigned long long unk20;
    TESCameraState* transitionFrom;
    TESCameraState* transitionTo;
    unsigned short unk38;
    unsigned char undefined_3a[6];
};
static_assert(sizeof(PlayerCameraTransitionState) == 64, "PlayerCameraTransitionState layout differs from the PDB");
