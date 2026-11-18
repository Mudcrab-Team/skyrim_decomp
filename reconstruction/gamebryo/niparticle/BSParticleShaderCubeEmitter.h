// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSParticleShaderCubeEmitter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSParticleShaderEmitter: STANDIN EXE_RTTI
// BSParticleShaderCubeEmitter::~BSParticleShaderCubeEmitter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10, unknownED0: GUESS(low)
// Generate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); signature from the sheet, not checked against the community header
#pragma once

#include <cstdint>
#include "../nimain/NiRefObject.h"

class NiPoint3;

class BSParticleShaderEmitter : public NiRefObject
{
public:
    std::uint8_t unknown10[0xEC0];  // 10
};
static_assert(sizeof(BSParticleShaderEmitter) == 0xED0, "BSParticleShaderEmitter size");

class BSParticleShaderCubeEmitter : public BSParticleShaderEmitter
{
public:
    BSParticleShaderCubeEmitter();
    virtual bool Generate(bool a_arg1, NiPoint3& a_arg2, NiPoint3& a_arg3);
    virtual ~BSParticleShaderCubeEmitter();  // compared: 0x2a0b60 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknownED0[0x110];  // ED0
};
static_assert(sizeof(BSParticleShaderCubeEmitter) == 0xFE0, "BSParticleShaderCubeEmitter size");
