// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaSplineCompressedAnimation; size 0xb0
#pragma once

#include "hkArray_unsigned_char_c72971e9.h"
#include "hkArray_unsigned_int_3dd3cd32.h"
#include "hkaAnimation.h"
struct hkaSplineCompressedAnimation {
    hkaAnimation _base;
    int numFrames;
    int numBlocks;
    int maxFramesPerBlock;
    int maskAndQuantizationSize;
    float blockDuration;
    float blockInverseDuration;
    float frameDuration;
    unsigned int pad54;
    hkArray_unsigned_int_3dd3cd32 blockOffsets;
    hkArray_unsigned_int_3dd3cd32 floatBlockOffsets;
    hkArray_unsigned_int_3dd3cd32 transformOffsets;
    hkArray_unsigned_int_3dd3cd32 floatOffsets;
    hkArray_unsigned_char_c72971e9 data;
    int endian;
    unsigned int padAC;
};
static_assert(sizeof(hkaSplineCompressedAnimation) == 176, "hkaSplineCompressedAnimation layout differs from the PDB");
