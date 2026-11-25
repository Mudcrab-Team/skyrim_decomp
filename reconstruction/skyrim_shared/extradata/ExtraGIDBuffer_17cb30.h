// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// ExtraGIDBuffer, ~ExtraGIDBuffer, BSExtraData, ~BSExtraData, GetType, IsNotEqual, next, buffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// opaque18: GUESS(low); unobserved trailing storage retained for measured deallocation size.
// 0x17cb30 ExtraGIDBuffer::~ExtraGIDBuffer
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
class BSExtraData {
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData*) const;
    BSExtraData* next;
};
class ExtraGIDBuffer : public BSExtraData {
public:
    ExtraGIDBuffer();
    ~ExtraGIDBuffer() override;
    std::uint32_t GetType() const override;
    bool IsNotEqual(const BSExtraData*) const override;
    std::int8_t* buffer;
    std::uint64_t opaque18;
};
static_assert(sizeof(ExtraGIDBuffer) == 0x20, "ExtraGIDBuffer size");
