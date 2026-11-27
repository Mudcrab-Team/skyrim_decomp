// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendInterpolator, NiBlendInterpolator::NiBlendInterpolator: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpolator, NiObject, NiRefObject, lastTime, _refCount, DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags, arraySize, interpolatorCount, singleIndex, highPriority, nextHighPriority, interpArray, singleInterpolator, weightThreshold, singleTime, highWeightSum, nextHighWeightSum, highEaseSpinner: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    std::uint32_t _refCount;
};
class NiObject : public NiRefObject
{
public:
    NiObject();
    ~NiObject() override;
};
class NiInterpolator : public NiObject
{
public:
    NiInterpolator();
    ~NiInterpolator() override;
    float lastTime;
};
class NiBlendInterpolator : public NiInterpolator
{
public:
    NiBlendInterpolator();
    ~NiBlendInterpolator() override;
    std::uint8_t flags;
    std::uint8_t arraySize;
    std::uint8_t interpolatorCount;
    std::uint8_t singleIndex;
    std::int8_t highPriority;
    std::int8_t nextHighPriority;
    void* interpArray;
    NiInterpolator* singleInterpolator;
    float weightThreshold;
    float singleTime;
    float highWeightSum;
    float nextHighWeightSum;
    float highEaseSpinner;
};
static_assert(offsetof(NiBlendInterpolator, flags) == 0x18, "blend flag offset");
static_assert(offsetof(NiBlendInterpolator, interpArray) == 0x20, "blend array offset");
static_assert(offsetof(NiBlendInterpolator, highEaseSpinner) == 0x40, "blend ease offset");
static_assert(sizeof(NiBlendInterpolator) == 0x48, "blend size");
