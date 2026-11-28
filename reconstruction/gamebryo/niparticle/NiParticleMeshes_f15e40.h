// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiParticleMeshes, NiParticleMeshes::SetSelectiveUpdateFlags_140C89470: CRASHLOGGER_PDB(59818@2026.10.24)
// NiParticles, NiAVObject, NiParticleMeshesData, SetSelectiveUpdateFlags, modelData, meshRoot, flags: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiAVObject
{
public:
    virtual ~NiAVObject();  // 00
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
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // 2B (0x158)

    std::uint8_t unk08[0xEC];  // 08
    std::uint32_t flags;  // F4
};
static_assert(offsetof(NiAVObject, flags) == 0xF4, "flags offset");

struct NiParticleMeshesData
{
    std::uint8_t unk00[0x90];  // 00
    NiAVObject* meshRoot;  // 90
};
static_assert(offsetof(NiParticleMeshesData, meshRoot) == 0x90, "meshRoot offset");

class NiParticles
{
public:
    virtual ~NiParticles();
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);

    std::uint8_t unk08[0x150];  // 08
    NiParticleMeshesData* modelData;  // 158
};
static_assert(offsetof(NiParticles, modelData) == 0x158, "modelData offset");

class NiParticleMeshes : public NiParticles
{
public:
    void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // compared: 0xf15e40
};
