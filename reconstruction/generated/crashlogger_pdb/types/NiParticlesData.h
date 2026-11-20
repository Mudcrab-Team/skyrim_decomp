// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiParticlesData; size 0x90
#pragma once

#include "NiBound_6900288c.h"
#include "NiObject_de5bc370.h"
struct NiColorA_7eee66f4;
struct NiPoint3;
struct NiQuaternion;
struct NiParticlesData {
    NiObject_de5bc370 _base;
    bool hasRotations;
    unsigned char unk11;
    unsigned short maxNumVertices;
    NiBound_6900288c bound;
    unsigned int pad24;
    NiQuaternion* rotations;
    NiPoint3* positions;
    NiColorA_7eee66f4* color;
    float* radii;
    float* sizes;
    float* rotationAngles;
    NiPoint3* rotationAxes;
    NiColorA_7eee66f4* subtextureOffsets;
    unsigned int subTextureOffsetsCount;
    float aspectRatio;
    float speedToAspectAspect2;
    float speedToAspectAspect1;
    float speedToAspectSpeed2;
    unsigned short numVertices;
    unsigned short pad7E;
    unsigned char* textureIndices;
    unsigned char unk88;
    unsigned char unk89;
    unsigned short pad8A;
    unsigned int pad8C;
};
static_assert(sizeof(NiParticlesData) == 144, "NiParticlesData layout differs from the PDB");
