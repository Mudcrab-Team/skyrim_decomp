// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: Stand-in declarations from the labelled sources and the pinned image layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLookAtInterpolator::~NiLookAtInterpolator: CRASHLOGGER_PDB(59818@2026.10.24)
// NiLookAtInterpolator, m_kTargetNodeName, m_pItems: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// BSFixedString, NiInterpolator, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// _ptr: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString::Copy: OBSERVED
// emptyLookAtName, unk08, unk18, unk30: GUESS(low)
#pragma once

#include <cstdint>

class BSFixedString
{
public:
    ~BSFixedString();
    void Copy(const BSFixedString& source);

private:
    // _data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    const char* _data;
};

class NiInterpolator
{
public:
    virtual ~NiInterpolator();

private:
    std::uint8_t unk08[0x10];
};

template <class T>
class NiPointer
{
public:
    ~NiPointer();

private:
    T* _ptr;
};

class NiLookAtInterpolator : public NiInterpolator
{
public:
    ~NiLookAtInterpolator() override;

private:
    std::uint8_t unk18[0x10];
    BSFixedString m_kTargetNodeName;
    std::uint8_t unk30[0x20];
    NiPointer<NiInterpolator> m_pItems[3];
};

extern const BSFixedString emptyLookAtName;
