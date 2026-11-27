// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// BSLimbIKModifierUtility, BSLimbIKModifierUtility::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// BSLimbIKBase, BSTSingletonBase, gLimbIKSingleton, unk08: GUESS
#pragma once

#include <cstdint>

class BSLimbIKModifierUtility;

extern BSLimbIKModifierUtility* gLimbIKSingleton;

class BSLimbIKBase
{
public:
    BSLimbIKBase();
    virtual ~BSLimbIKBase();
};

class BSTSingletonBase
{
public:
    ~BSTSingletonBase()
    {
        gLimbIKSingleton = nullptr;
    }

    std::uint8_t unk08;
};

class BSLimbIKModifierUtility : public BSLimbIKBase, public BSTSingletonBase
{
public:
    BSLimbIKModifierUtility();
    ~BSLimbIKModifierUtility() override
    {
    }
};

static_assert(sizeof(BSLimbIKModifierUtility) == 0x10, "BSLimbIKModifierUtility size");
