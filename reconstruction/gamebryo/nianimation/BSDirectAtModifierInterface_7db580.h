// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// BSDirectAtModifierInterface, BSDirectAtModifierInterface::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// BSDirectAtBase, BSTSingletonBase, gDirectAtSingleton, unk08: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class BSDirectAtModifierInterface;

extern BSDirectAtModifierInterface* gDirectAtSingleton;

class BSDirectAtBase
{
public:
    BSDirectAtBase();
    virtual ~BSDirectAtBase();
};

class BSTSingletonBase
{
public:
    BSTSingletonBase();

    std::uint8_t unk08;
};

class BSDirectAtModifierInterface : public BSDirectAtBase, public BSTSingletonBase
{
public:
    BSDirectAtModifierInterface();
};

inline BSTSingletonBase::BSTSingletonBase()
{
    gDirectAtSingleton = static_cast<BSDirectAtModifierInterface*>(this);
}

static_assert(sizeof(BSDirectAtModifierInterface) == 0x10, "BSDirectAtModifierInterface size");
