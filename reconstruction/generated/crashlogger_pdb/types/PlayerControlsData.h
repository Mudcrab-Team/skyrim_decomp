// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerControlsData; size 0x30
#pragma once

#include "NiPoint2_6bdffc9f.h"
struct PlayerControlsData {
    NiPoint2_6bdffc9f moveInputVec;
    NiPoint2_6bdffc9f lookInputVec;
    NiPoint2_6bdffc9f prevMoveVec;
    NiPoint2_6bdffc9f prevLookVec;
    unsigned int unk20;
    bool autoMove;
    bool running;
    unsigned char unk26;
    bool fovSlideMode;
    bool povScriptMode;
    bool povBeastMode;
    unsigned char unk2A;
    bool setupHeldStatesForRelease;
    bool remapMode;
    unsigned char unk2D;
    unsigned short unk2E;
};
static_assert(sizeof(PlayerControlsData) == 48, "PlayerControlsData layout differs from the PDB");
