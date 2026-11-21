// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceEffectDepthOfField; size 0x158
#pragma once

#include "ImageSpaceEffectOption.h"
struct ImageSpaceEffectDepthOfField {
    ImageSpaceEffectOption _base;
    unsigned long long unk0A8;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned char unk0C0;
    unsigned char unk0C1;
    unsigned short unk0C2;
    unsigned int unk0C4;
    unsigned char unk0C8_raw[128];
    bool enabled;
    unsigned char undefined_149[3];
    float unk14C;
    float unk150;
    unsigned int pad154;
};
static_assert(sizeof(ImageSpaceEffectDepthOfField) == 344, "ImageSpaceEffectDepthOfField layout differs from the PDB");
