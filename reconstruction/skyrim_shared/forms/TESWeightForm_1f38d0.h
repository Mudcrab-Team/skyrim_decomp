// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWeightForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}
};

class TESWeightForm : public BaseFormComponent
{
public:
    TESWeightForm();
    ~TESWeightForm() override = default;

private:
    std::uint8_t padding08[0x8];
};
static_assert(sizeof(TESWeightForm) == 0x10, "observed allocation size");
