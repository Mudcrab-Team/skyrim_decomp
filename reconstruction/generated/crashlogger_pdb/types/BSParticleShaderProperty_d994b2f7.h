// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderProperty; size 0x198
// one of 2 different PDB types sharing this name
#pragma once

#include "BSShaderProperty.h"
#include "BSTArray_RE__NiPointer_RE__BSParticleShaderEmitter_ab97d623_d35a5aa0.h"
#include "NiColorA.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__BSParticleShaderGeometry_65410149.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSParticleShaderEmitter;
struct BSParticleShaderProperty_d994b2f7 {
    BSShaderProperty _base;
    bool useWorldSpace;
    bool particleGreyscaleAlpha;
    unsigned char unk8B;
    unsigned char undefined_8b[1];
    float particleLifetime;
    float particleLifetimeVariance;
    float initialSpeedAlongNormal;
    float initialSpeedAlongNormalVariance;
    float accelerationAlongNormal;
    float initialVelocity1;
    float initialVelocity2;
    float intialVelocity3;
    float acceleration1;
    float acceleration2;
    float acceleration3;
    float birthPositionOffset;
    float birthPositionVarianceOffset;
    float particleShaderInitialRotation;
    float intialRotationVariance;
    float rotationSpeed;
    float rotationSpeedVariance;
    bool unk0D0;
    unsigned char pad0D1;
    unsigned short pad0D2;
    float animatedStartFrame;
    float animatedStartFrameVariance;
    float animatedEndFrame;
    float animatedEndFrameVariance;
    float animatedLoopStartVariance;
    float animatedFrameCount;
    float animatedFrameCountVariance;
    unsigned int colorScale;
    float colorKey1Time;
    float colorKey2Time;
    float colorKey3Time;
    NiColorA colorKey1;
    NiColorA colorKey2;
    NiColorA colorKey3;
    float scaleKey1;
    float scaleKey2;
    float scaleKey1Time;
    float scaleKey2Time;
    NiPointer_RE__NiSourceTexture_cf356212 particleShaderTexture;
    NiPointer_RE__NiSourceTexture_cf356212 particlePaletteTexture;
    BSTArray_RE__NiPointer_RE__BSParticleShaderEmitter_ab97d623_d35a5aa0 particleEmitters;
    NiPointer_RE__BSParticleShaderGeometry_65410149 particleShaderGeometry;
    float unk170;
    float textureCountU;
    float textureCountV;
    NiPoint3_a7124070 windPoint;
    float explosionWindSpeed;
    unsigned int unk18C;
    BSParticleShaderEmitter* particleEmitter;
};
static_assert(sizeof(BSParticleShaderProperty_d994b2f7) == 408, "BSParticleShaderProperty_d994b2f7 layout differs from the PDB");
