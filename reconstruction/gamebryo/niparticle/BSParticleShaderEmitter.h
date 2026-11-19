// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BSParticleShaderEmitter, BSParticleShaderEmitter::~BSParticleShaderEmitter, BSParticleShaderEmitter::GetBoundsObject, BSParticleShaderEmitter::Generate, BSParticleShaderEmitter::TextureAnimInfo, BSParticleShaderEmitter::ParticleData, property, emitterType, particleCount, alpha, generateReminder, maxParticleRatio, textureAnims, instanceData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets and sizes as declared there; the property and emitterType types are guesses (NG: BSParticleShaderProperty* and an enumeration)
// NiAVObject, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiRefObject.h"

class NiAVObject;
class NiPoint3;

class BSParticleShaderEmitter : public NiRefObject
{
public:
    struct TextureAnimInfo
    {
        float currentFrame;         // 00
        std::uint32_t totalFrames;  // 04
    };
    static_assert(sizeof(TextureAnimInfo) == 0x08, "TextureAnimInfo size");

    struct ParticleData
    {
        float XPos;              // 00
        float YPos;              // 04
        float ZPos;              // 08
        float age;               // 0C
        float XVel;              // 10
        float YVel;              // 14
        float ZVel;              // 18
        float lifeAdjust;        // 1C
        float rotationStart;     // 20
        float rotationSpeed;     // 24
        float speedMult;         // 28
        std::uint8_t texCoordU;  // 2C
        std::uint8_t texCoordV;  // 2D
        std::uint8_t vertexX;    // 2E
        std::uint8_t vertexY;    // 2F
    };
    static_assert(sizeof(ParticleData) == 0x30, "ParticleData size");

    // No user-declared destructor: the compared 0x2a0ba0 is the generated deleting form (slot 00),
    // which calls the base destructor and never stores a vftable.
    virtual NiAVObject* GetBoundsObject();    // 02
    virtual bool Generate(bool a_arg1, NiPoint3& a_arg2, NiPoint3& a_arg3) = 0;  // 03
    BSParticleShaderEmitter();

    void* property;                  // 10
    std::uint16_t emitterType;       // 18
    std::uint16_t particleCount;     // 1A
    float alpha;                     // 1C
    float generateReminder;          // 20
    float maxParticleRatio;          // 24
    TextureAnimInfo* textureAnims;   // 28
    ParticleData instanceData[78];   // 30
};
static_assert(sizeof(BSParticleShaderEmitter) == 0xED0, "BSParticleShaderEmitter size");
