// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: none
// BGSParticleArrayAttach, BGSParticleArrayAttach::CollectEmitterPolicy, BGSParticleArrayAttach::CollectEmitterPolicy::Func2_1401A6F20: CRASHLOGGER_PDB(59818@2026.10.24)
// EmitterArray, EmitterArray::Clear, EmitterArray::Deallocate, emitters, unk00, unk0C, unk14: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct EmitterArray
{
    void Deallocate();
    void Clear()
    {
        if (data) {
            Deallocate();
            size = 0;
        }
    }

    void** data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};
static_assert(sizeof(EmitterArray) == 0x18, "EmitterArray size");

class BGSParticleArrayAttach
{
public:
    class CollectEmitterPolicy
    {
    public:
        void Func2_1401A6F20();

        std::uint64_t unk00;
        EmitterArray emitters;
    };
};
static_assert(offsetof(BGSParticleArrayAttach::CollectEmitterPolicy, emitters) == 0x08, "emitters offset");
