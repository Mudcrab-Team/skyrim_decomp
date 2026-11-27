// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiRefObject, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::~NiRefObject, NiRefObject::DeleteThis, NiRefObject::_refCount, NiObject::~NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::NiObject: OBSERVED
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData: EXE_RTTI
// NiExtraData::name, NiExtraData::~NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraData::NiExtraData: OBSERVED
#pragma once

#include <cstdint>

// Only the slots and members this unit needs; the NiObject constructor is out of line, as the image calls it.
class NiRefObject
{
public:
    virtual ~NiRefObject();     // 00
    virtual void DeleteThis();  // 01

    std::uint32_t _refCount;  // 08
};

class NiObject : public NiRefObject
{
public:
    NiObject();
    ~NiObject() override;
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class BSFixedString
{
public:
    ~BSFixedString();

    const char* _data{ nullptr };  // 00
};

class NiExtraData : public NiObject
{
public:
    NiExtraData();
    ~NiExtraData() override;

    BSFixedString name;  // 10
};
static_assert(sizeof(NiExtraData) == 0x18, "NiExtraData size");
