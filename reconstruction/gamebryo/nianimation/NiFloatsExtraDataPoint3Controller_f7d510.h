// Source exposure: mixed (pinned-image observations and labelled naming/declaration sources).
// Code origin: original handwritten implementation from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatsExtraDataPoint3Controller: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiExtraDataController: EXE_RTTI STANDIN; opaque partial base layout, constructor boundary retained.
// valueIndex, pointData: GUESS(low); roles inferred from constructor defaults only.
#pragma once
#include <cstdint>

class NiExtraDataController
{
public:
    NiExtraDataController();
    virtual ~NiExtraDataController();
    std::uint8_t unknown08[0x58];
};
static_assert(sizeof(NiExtraDataController) == 0x60, "extra-data controller base size");

class NiFloatsExtraDataPoint3Controller : public NiExtraDataController
{
public:
    NiFloatsExtraDataPoint3Controller();
    ~NiFloatsExtraDataPoint3Controller() override;
    std::uint32_t valueIndex;
    void* pointData;
};
