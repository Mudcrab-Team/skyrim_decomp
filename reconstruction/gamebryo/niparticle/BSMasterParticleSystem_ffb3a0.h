// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: reconstruction from the pinned image listing; see Adapted bodies.
// Adapted bodies: SaveStreamValue, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// BSMasterParticleSystem, BSMasterParticleSystem::SaveBinary_140D5DE00, maxEmitterObj: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, NiNode::SaveBinary, NiStream, NiParticles: CRASHLOGGER_PDB(59818@2026.10.24)
// particlesData, particlesCount, NiBinaryStream, absoluteCurrentPos, writeFn, SaveLinkID, unknown00, unknown10, unknown128, unknown148, unknown154: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiParticles;

class NiBinaryStream
{
public:
    using WriteFn = std::uint32_t (*)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    std::uint8_t unknown00[0x8];
    std::uint32_t absoluteCurrentPos;  // 08
    std::uint32_t reserved0C;          // 0C
    std::uint8_t unknown10[0x8];       // 10
    WriteFn writeFn;                   // 18
};
static_assert(offsetof(NiBinaryStream, writeFn) == 0x18, "writeFn offset");

class NiStream
{
public:
    virtual ~NiStream();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void SaveLinkID(NiParticles* a_object);  // slot 0C (+0x60)

    std::uint8_t unknown08[0x298];
    NiBinaryStream* binaryStream;  // 2A0
};
static_assert(offsetof(NiStream, binaryStream) == 0x2A0, "binaryStream offset");

class NiNode
{
public:
    virtual ~NiNode();
    virtual void SaveBinary(NiStream& a_stream);

    std::uint8_t unknown08[0x120];
};
static_assert(sizeof(NiNode) == 0x128, "NiNode size");

class BSMasterParticleSystem : public NiNode
{
public:
    void SaveBinary_140D5DE00(NiStream& a_stream);  // compared: 0xffb3a0

    std::uint8_t unknown128[0x18];
    NiParticles** particlesData;   // 140
    std::uint64_t unknown148;      // 148
    std::uint32_t particlesCount;  // 150
    std::uint8_t unknown154[0xE];  // 154
    std::uint16_t maxEmitterObj;   // 162
};
static_assert(offsetof(BSMasterParticleSystem, particlesData) == 0x140, "particlesData offset");
static_assert(offsetof(BSMasterParticleSystem, particlesCount) == 0x150, "particlesCount offset");
static_assert(offsetof(BSMasterParticleSystem, maxEmitterObj) == 0x162, "maxEmitterObj offset");
