// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// NiOBBRoot, NiOBBRoot::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// NiOBBNode, unk08, rootNode, unk18: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiOBBNode
{
public:
    virtual ~NiOBBNode();
};

class NiOBBRoot
{
public:
    NiOBBRoot();
    virtual ~NiOBBRoot()
    {
        delete rootNode;
    }

    std::uint8_t unk08[0x8];
    NiOBBNode* rootNode;
    std::uint8_t unk18[0x48];
};

static_assert(offsetof(NiOBBRoot, rootNode) == 0x10, "rootNode offset");
static_assert(sizeof(NiOBBRoot) == 0x60, "NiOBBRoot size");
