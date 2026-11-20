// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend base and stream prefixes reflect the measured fields, virtual slots, and cited declarations.
// NiBlendInterpolator: EXE_RTTI
// NiInterpolator, NiObject, NiStream, NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiInterpolator::IsBoolValueSupported, ::IsFloatValueSupported, ::IsQuaternionValueSupported, ::IsPoint3ValueSupported, ::IsColorAValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, padding, BlendValueSupport: GUESS(low)
#pragma once

#include "NiInterpolator.h"

class NiBlendInterpolator : public NiInterpolator
{
public:
    NiBlendInterpolator();
    ~NiBlendInterpolator() override;

    void CopyMembers(NiBlendInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;

private:
    std::uint8_t padding18[0x30];
};
static_assert(sizeof(NiBlendInterpolator) == 0x48, "blend interpolator prefix size");

// BlendValueSupport: STANDIN GUESS(low); preserves the NiInterpolator slots queried by the blend classes.
class BlendValueSupport : public NiObject
{
public:
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved2A();
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
};

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
