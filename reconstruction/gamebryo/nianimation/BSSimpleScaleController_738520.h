// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSSimpleScaleController: EXE_RTTI
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiTimeController
{
public:
    virtual ~NiTimeController();

private:
    std::uint8_t padding08[0x40];
};

class BSSimpleScaleController : public NiTimeController
{
public:
    BSSimpleScaleController();
    ~BSSimpleScaleController() override;

private:
    std::uint8_t padding48[0x10];
};
static_assert(sizeof(BSSimpleScaleController) == 0x58, "observed allocation size");
