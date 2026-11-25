// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces. Stamped as a twin of matched 0xf634d0 (gamebryo/nianimation/NiTransformInterpolator_f634d0): source copied, names replaced by placeholders.
// Ownerfc1cd0, RegisterKeyBasedStreamables_fc1cd0: GUESS(low) STANDIN
// RegisterStreamables, SaveBinary, GetKeyCount, GetKeyType, GetKeyContent, GetKeyArray, GetKeyStride, GuaranteeTimeRange, value, data: GUESS(low) STANDIN
#pragma once
#include "NiTransformInterpolator_f634d0.h"

class Ownerfc1cd0 : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    std::uint32_t GetKeyCount(std::uint16_t channel) const;
    KeyType GetKeyType(std::uint16_t channel) const;
    KeyContent GetKeyContent(std::uint16_t channel) const;
    void* GetKeyArray(std::uint16_t channel) const;
    std::uint8_t GetKeyStride(std::uint16_t channel) const;
    void GuaranteeTimeRange(float start, float end);

private:
    NiQuatTransform value;
    NiTransformData* data;
};
