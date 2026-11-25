// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: original hand-written reconstruction; declarations adapted from the labelled community header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPrimitive, ExtraPrimitive::~ExtraPrimitive, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSPrimitive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the observed destructor slot
// ExtraPrimitive::primitive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraPrimitive::ExtraPrimitive: GUESS(low); stand-in constructor to emit the virtual table
// BSExtraData::unknown08: GUESS(low); unaccessed base storage
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    std::uint64_t unknown08;  // 08, unaccessed base storage
};

class BGSPrimitive
{
public:
    virtual ~BGSPrimitive();
};

class ExtraPrimitive : public BSExtraData
{
public:
    ExtraPrimitive();
    ~ExtraPrimitive() override;

    BGSPrimitive* primitive;  // 10
};
static_assert(sizeof(ExtraPrimitive) == 0x18, "ExtraPrimitive size");
// 0x17d610 ExtraPrimitive::~ExtraPrimitive
