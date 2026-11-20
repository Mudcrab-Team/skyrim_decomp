// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFadeNode; size 0x158
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiNode.h"
struct BSFadeNode {
    NiNode _base;
    float unk128;
    float unk12C;
    float currentFade;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    float unk140;
    unsigned int unk144;
    unsigned int unk148;
    float unk14C;
    unsigned short unk150;
    unsigned char unk152;
    unsigned char unk153;
    unsigned char unk154;
    unsigned char unk155;
    unsigned short unk156;
};
static_assert(sizeof(BSFadeNode) == 344, "BSFadeNode layout differs from the PDB");
