// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ExtraInfoGeneralTopic::~ExtraInfoGeneralTopic follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1996
// ExtraInfoGeneralTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraInfoGeneralTopic::~ExtraInfoGeneralTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraInfoGeneralTopic::Data, ::unk10, Data::unk48: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the destructor clears the first byte of unk48.
// Data::~Data, unknown00, unknown49: GUESS(low); topic payload cleanup and opaque storage.
#pragma once

#include <cstdint>

void operator delete(void*, unsigned __int64) noexcept;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData* rhs) const;

    BSExtraData* next;
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");



class ExtraInfoGeneralTopic : public BSExtraData
{
public:
    struct Data
    {
        ~Data();
        std::uint64_t unknown00[9];
        bool unk48;
        std::uint8_t unknown49[0xF];
    };
    static_assert(sizeof(Data) == 0x58, "topic data size");

    ExtraInfoGeneralTopic();
    ~ExtraInfoGeneralTopic() override;

    Data* unk10;
};
static_assert(sizeof(ExtraInfoGeneralTopic) == 0x18, "ExtraInfoGeneralTopic size");
