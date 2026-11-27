// Source exposure: mixed (CrashLogger PDB names; the pinned image listing).
// Code origin: original; class names from the CrashLogger PDB output, members and the signature read from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BShkFloatController: CRASHLOGGER_PDB(59818@2026.10.24); 0x18 bytes, derives from BShkNonTransformController
// BShkNonTransformController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); 0x18 bytes, only slot 0 of its four virtual slots is declared
// BShkFloatController::GetRawValue: CRASHLOGGER_PDB(59818@2026.10.24); the PDB prototype lists only the object, the listing reads a second argument and returns a float
// BShkNonTransformController::~BShkNonTransformController: GUESS(low); slot 0 takes a delete flag in the PDB vtable
// BShkNonTransformController::variableIndex, BShkNonTransformController::unk0C, BShkNonTransformController::unk10: GUESS(low)
// BShkFloatVariables, BShkFloatVariables::unk00, BShkFloatVariables::numFloats, BShkFloatVariables::floatsOffset, BShkFloatVariables::GetFloats: GUESS(low)
// BShkVariableSource, BShkVariableSource::variables: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// A block holding a float table at a self-relative byte offset.
struct BShkFloatVariables
{
    const float* GetFloats() const
    {
        // floatsOffset is a byte offset stored in each block, measured from the block start.
        return reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + floatsOffset);
    }

    std::uint8_t unk00[0x42];   // 00
    std::int16_t numFloats;     // 42
    std::int16_t floatsOffset;  // 44, byte offset from the block start to its float table
};

struct BShkVariableSource
{
    const BShkFloatVariables* variables;  // 00
};

class BShkNonTransformController
{
public:
    virtual ~BShkNonTransformController();  // 00

    std::uint32_t variableIndex;  // 08
    std::uint32_t unk0C;          // 0C
    std::uint64_t unk10;          // 10
};
static_assert(sizeof(BShkNonTransformController) == 0x18, "BShkNonTransformController size from the PDB");

class BShkFloatController : public BShkNonTransformController
{
public:
    float GetRawValue(const BShkVariableSource& a_source) const;  // compared: 0xbdd230
};
static_assert(sizeof(BShkFloatController) == 0x18, "BShkFloatController size from the PDB");
