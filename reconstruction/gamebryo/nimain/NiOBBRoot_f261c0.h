// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiOBBRoot, NiOBBRoot::Func1_140CA81B0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiOBBNode, Unk_00, Unk_01, TestCollision, unk00, rootNode, unk18, deltaTime: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiOBBNode
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual bool TestCollision(
        NiOBBNode* a_other,
        void* a_arg2,
        void* a_arg3,
        std::uint32_t a_arg4,
        std::uint32_t a_arg5,
        std::uint32_t a_dt0,
        std::uint32_t a_dt1);
};

class NiOBBRoot
{
public:
    bool Func1_140CA81B0(
        NiOBBRoot* a_other,
        void* a_arg2,
        void* a_arg3,
        std::uint32_t a_arg4,
        std::uint32_t a_arg5);

    std::uint8_t unk00[0x10];
    NiOBBNode* rootNode;
    std::uint8_t unk18[0x44];
    std::uint32_t deltaTime;
};

static_assert(offsetof(NiOBBRoot, rootNode) == 0x10, "rootNode offset");
static_assert(offsetof(NiOBBRoot, deltaTime) == 0x5C, "deltaTime offset");
