// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the spline base and stream fields follow pinned offsets and the cited public declarations.
// NiBSplineInterpolator: EXE_RTTI
// NiInterpolator, NiObject, NiCloningProcess, NiStream, NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBSplineData, NiBSplineBasisData, CopyMembers, Slot39, GetControlPointCount, padding: STANDIN GUESS(low)
#pragma once

#include "NiInterpolator.h"

class NiBSplineData;
class NiBSplineBasisData;

class NiBSplineInterpolator : public NiInterpolator
{
public:
    NiBSplineInterpolator(NiBSplineData* data, NiBSplineBasisData* basis);
    ~NiBSplineInterpolator() override;
    void CopyMembers(NiBSplineInterpolator* dest, NiCloningProcess& cloning);
    virtual void Slot39();
    virtual std::uint32_t GetControlPointCount(std::uint16_t channel) const;

private:
    std::uint8_t padding18[0x18];
};
static_assert(sizeof(NiBSplineInterpolator) == 0x30, "spline base size");

// _absoluteCurrentPos, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBinaryStream
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    virtual ~NiBinaryStream();

    std::uint32_t _absoluteCurrentPos;
    std::uint32_t padding0C;
    ReadFn* _readFn;
    WriteFn* _writeFn;
};

// iStr, oStr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream
{
public:
    std::uint8_t padding[0x298];
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
};
static_assert(offsetof(NiStream, iStr) == 0x298, "stream input offset");
static_assert(offsetof(NiStream, oStr) == 0x2A0, "stream output offset");
