// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendInterpolator: STANDIN EXE_RTTI
// NiPoint3, NiColorA, NiQuaternion, x, y, z, w, red, green, blue, alpha, NiInterpolator::IsTransformValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BlendSourceInterpolator, Slot25, Slot2B..Slot2F, UpdateColor, UpdatePoint, UpdateRotation, UpdateFloat, UpdateBool: GUESS(low)
// unknown19, unknown30, unknown38, flags, cachedTime, source: GUESS(low)
#pragma once

#include "bssystem/NiStream_19e930.h"

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiColorA
{
    float red;
    float green;
    float blue;
    float alpha;
};

struct NiQuaternion
{
    float w;
    float x;
    float y;
    float z;
};

// The update methods occupy consecutive slots in the input interpolator.
class BlendSourceInterpolator : public NiObject
{
public:
    virtual void Slot25();
    virtual bool UpdateColor(float time, NiObjectNET* target, NiColorA& value);
    virtual bool UpdatePoint(float time, NiObjectNET* target, NiPoint3& value);
    virtual bool UpdateRotation(float time, NiObjectNET* target, NiQuaternion& value);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& value);
    virtual bool UpdateBool(float time, NiObjectNET* target, bool& value);
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual bool IsTransformValueSupported() const;
};

class NiBlendInterpolator : public NiInterpolator
{
public:
    NiBlendInterpolator();
    NiBlendInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    ~NiBlendInterpolator() override;
    void LoadBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;

protected:
    std::uint8_t flags;
    std::uint8_t unknown19[0xf];
    BlendSourceInterpolator* source;
    std::uint32_t unknown30;
    float cachedTime;
    std::uint8_t unknown38[0x10];
};
static_assert(sizeof(NiBlendInterpolator) == 0x48, "blend base size");
