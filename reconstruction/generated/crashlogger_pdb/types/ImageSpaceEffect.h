// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceEffect; size 0x90
#pragma once

#include "NiTPrimitiveArray_RE__ImageSpaceEffectParam_388f62a4.h"
#include "NiTPrimitiveArray_RE__ImageSpaceEffect_8c3f9e6d.h"
#include "NiTPrimitiveArray_RE__ImageSpaceEffect__EffectInput_a6e4821d.h"
#include "NiTPrimitiveArray_RE__ImageSpaceTexture_23fd4caa.h"
#include "NiTPrimitiveArray_int_cd02a6d8.h"
struct ImageSpaceEffect_vtbl;
struct ImageSpaceEffect {
    ImageSpaceEffect_vtbl* __vftable;
    bool active;
    bool unk09;
    unsigned short pad0A;
    unsigned int pad0C;
    NiTPrimitiveArray_RE__ImageSpaceEffect_8c3f9e6d effects;
    NiTPrimitiveArray_RE__ImageSpaceEffectParam_388f62a4 effectParams;
    NiTPrimitiveArray_RE__ImageSpaceTexture_23fd4caa effectTextures;
    NiTPrimitiveArray_RE__ImageSpaceEffect__EffectInput_a6e4821d effectInputs;
    NiTPrimitiveArray_int_cd02a6d8 unk70;
    bool unk88;
    unsigned char pad89;
    unsigned short pad8A;
    unsigned int pad8C;
};
static_assert(sizeof(ImageSpaceEffect) == 144, "ImageSpaceEffect layout differs from the PDB");
