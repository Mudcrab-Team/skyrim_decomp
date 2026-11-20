// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderCubeEmitter; size 0xfe0
#pragma once

#include "BSParticleShaderEmitter_8e4e6f31.h"
#include "NiPoint3.h"
#include "XMFLOAT4X4.h"
struct BSParticleShaderCubeEmitter {
    BSParticleShaderEmitter_8e4e6f31 _base;
    XMFLOAT4X4 occlusionProjection;
    NiPoint3 cameraOffsetVector;
    NiPoint3 offsetVector;
    NiPoint3 compositeOffsetVector;
    NiPoint3 frameVelocityVector;
    NiPoint3 windVelocity;
    NiPoint3 gravityVelocity;
    float rotation;
    float rotationVelocity;
    float cubeSize;
    float density;
    unsigned char instanceOffsets_raw[120];
};
static_assert(sizeof(BSParticleShaderCubeEmitter) == 4064, "BSParticleShaderCubeEmitter layout differs from the PDB");
