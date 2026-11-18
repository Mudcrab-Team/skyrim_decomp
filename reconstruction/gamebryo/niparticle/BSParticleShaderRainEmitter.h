// Type declarations for the BSParticleShaderRainEmitter translation unit (build sse-steam-1-7-104).
//
// Labels: v2
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and the member offsets and types of those names follow the community declaration; no external implementation body is copied.
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// Community names are unverified. Only the members the compared code needs are declared.
// BSParticleShaderRainEmitter, BSParticleShaderRainEmitter::BSParticleShaderRainEmitter, BSParticleShaderRainEmitter::~BSParticleShaderRainEmitter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSParticleShaderEmitter, BSParticleShaderEmitter::~BSParticleShaderEmitter, _refCount, _pad0C, property, emitterType, particleCount, alpha, generateReminder, maxParticleRatio, textureAnims, instanceData, ParticleData, TextureAnimInfo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names, offsets and sizes as declared there (the NiRefObject members are flattened into BSParticleShaderEmitter), the pointer and enum types are guesses
// ParticleData::XPos, ParticleData::YPos, ParticleData::ZPos, ParticleData::age, ParticleData::XVel, ParticleData::YVel, ParticleData::ZVel, ParticleData::lifeAdjust, ParticleData::rotationStart, ParticleData::rotationSpeed, ParticleData::speedMult, ParticleData::texCoordU, ParticleData::texCoordV, ParticleData::vertexX, ParticleData::vertexY: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets follow the declared order, which puts the last four bytes at 0x2C to 0x2F where the community offset comments are stale
// TextureAnimInfo::currentFrame, TextureAnimInfo::totalFrames: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared as float and std::uint32_t there
// unkED0, unkED8, unkEE0, unkEE8, unkEF0, unkEF8, unkF00, unkF08, unkF10, unkF18, unkF20, unkF28, unkF30, unkF38, unkF40, unkF48, unkF50, unkF58, unkF60, unkF68, unkF70, unkF78, unkF80, unkF88, unkF90, unkF98, unkFA0, unkFA8, unkFB0, unkFB8, unkFC0, unkFC8, unkFD0, unkFD8: GUESS(low); storage after the community members that no compared code reads
// The MIT notice below covers only the names and declarations taken from
// CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; the other code in this file
// is covered by the repository licence and the provenance labels above.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once

#include <cstdint>

class BSParticleShaderEmitter {
public:
    struct TextureAnimInfo {
        float currentFrame;           // 00
        std::uint32_t totalFrames;    // 04
    };
    static_assert(sizeof(TextureAnimInfo) == 0x08, "TextureAnimInfo size");

    struct ParticleData {
        float XPos;                   // 00
        float YPos;                   // 04
        float ZPos;                   // 08
        float age;                    // 0C
        float XVel;                   // 10
        float YVel;                   // 14
        float ZVel;                   // 18
        float lifeAdjust;             // 1C
        float rotationStart;          // 20
        float rotationSpeed;          // 24
        float speedMult;              // 28
        std::uint8_t texCoordU;       // 2C
        std::uint8_t texCoordV;       // 2D
        std::uint8_t vertexX;         // 2E
        std::uint8_t vertexY;         // 2F
    };
    static_assert(sizeof(ParticleData) == 0x30, "ParticleData size");

    virtual ~BSParticleShaderEmitter();

    std::uint32_t _refCount;         // 08
    std::uint32_t _pad0C;            // 0C
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

class BSParticleShaderRainEmitter : public BSParticleShaderEmitter {
public:
    BSParticleShaderRainEmitter();
    virtual ~BSParticleShaderRainEmitter();  // compared: 0x2a0be0 (scalar deleting destructor)

    std::uint64_t unkED0;       // ED0
    std::uint64_t unkED8;       // ED8
    std::uint64_t unkEE0;       // EE0
    std::uint64_t unkEE8;       // EE8
    std::uint64_t unkEF0;       // EF0
    std::uint64_t unkEF8;       // EF8
    std::uint64_t unkF00;       // F00
    std::uint64_t unkF08;       // F08
    std::uint64_t unkF10;       // F10
    std::uint64_t unkF18;       // F18
    std::uint64_t unkF20;       // F20
    std::uint64_t unkF28;       // F28
    std::uint64_t unkF30;       // F30
    std::uint64_t unkF38;       // F38
    std::uint64_t unkF40;       // F40
    std::uint64_t unkF48;       // F48
    std::uint64_t unkF50;       // F50
    std::uint64_t unkF58;       // F58
    std::uint64_t unkF60;       // F60
    std::uint64_t unkF68;       // F68
    std::uint64_t unkF70;       // F70
    std::uint64_t unkF78;       // F78
    std::uint64_t unkF80;       // F80
    std::uint64_t unkF88;       // F88
    std::uint64_t unkF90;       // F90
    std::uint64_t unkF98;       // F98
    std::uint64_t unkFA0;       // FA0
    std::uint64_t unkFA8;       // FA8
    std::uint64_t unkFB0;       // FB0
    std::uint64_t unkFB8;       // FB8
    std::uint64_t unkFC0;       // FC0
    std::uint64_t unkFC8;       // FC8
    std::uint64_t unkFD0;       // FD0
    std::uint64_t unkFD8;       // FD8
};
static_assert(sizeof(BSParticleShaderRainEmitter) == 0xFE0, "BSParticleShaderRainEmitter size");
