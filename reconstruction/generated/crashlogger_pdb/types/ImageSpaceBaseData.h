// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceBaseData; size 0x50
#pragma once

#include "DepthOfField.h"
#include "Tint.h"
struct ImageSpaceBaseData {
    unsigned char hdr_raw[36];
    unsigned char cinematic_raw[12];
    Tint tint;
    DepthOfField depthOfField;
};
static_assert(sizeof(ImageSpaceBaseData) == 80, "ImageSpaceBaseData layout differs from the PDB");
