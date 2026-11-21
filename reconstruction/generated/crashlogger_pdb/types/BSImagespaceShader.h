// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSImagespaceShader; size 0x1a8
#pragma once

#include "BSShader.h"
#include "BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "ImageSpaceEffect.h"
struct BSComputeShader;
struct BSImagespaceShader {
    BSShader _base;
    ImageSpaceEffect _base_ImageSpaceEffect;
    unsigned char* name;
    unsigned char* originalShaderName;
    unsigned long long unk130;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 vsConstantNames;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 psConstantNames;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 samplerNames;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 uavNames;
    BSComputeShader* computeShader;
    bool unk1A0;
    bool isComputeShader;
    unsigned char undefined_1a2[6];
};
static_assert(sizeof(BSImagespaceShader) == 424, "BSImagespaceShader layout differs from the PDB");
