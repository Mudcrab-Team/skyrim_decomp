// Exposure detail: (community declarations and the pinned image).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiMeshParticleSystem, NiMeshParticleSystem::UpdateWorldData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAVObject, NiParticleSystem, NiTransform, NiUpdateData, local, world, particleData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MeshParticleData, target, unknownB0, unknown30, unknown3C, unknownB0to158, Slot: GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>

struct NiUpdateData;
struct NiTransform
{
    float rotate[9];
    float translate[3];
    float scale;
};

class NiAVObject
{
public:
    virtual void Slot00();
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
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void UpdateWorldData(NiUpdateData* data);
    std::uint8_t unknown08[0x40];
    NiTransform local;
    NiTransform world;
};
static_assert(offsetof(NiAVObject, local) == 0x48, "local offset");
static_assert(offsetof(NiAVObject, world) == 0x7C, "world offset");

struct MeshParticleData
{
    std::uint8_t unknown00[0xA8];
    NiAVObject* target;
};

class NiParticleSystem : public NiAVObject
{
public:
    void UpdateWorldData(NiUpdateData* data) override;
    std::uint8_t unknownB0to158[0xA8];
    MeshParticleData* particleData;
};
static_assert(offsetof(NiParticleSystem, particleData) == 0x158, "particleData offset");

class NiMeshParticleSystem : public NiParticleSystem
{
public:
    void UpdateWorldData(NiUpdateData* data) override;
};
