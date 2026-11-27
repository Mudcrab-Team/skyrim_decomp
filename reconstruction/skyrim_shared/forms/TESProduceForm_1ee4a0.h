// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESProduceForm.cpp:48
// TESProduceForm, ~TESProduceForm, InitializeDataComponent, ClearDataComponent, CopyComponent, harvestSound, produceItem, produceChance, pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSoundDescriptorForm, TESBoundObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"

class BGSSoundDescriptorForm;
class TESBoundObject;

class TESProduceForm : public BaseFormComponent
{
public:
    ~TESProduceForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03, compared: 0x1ee4a0

    BGSSoundDescriptorForm* harvestSound;  // 08
    TESBoundObject* produceItem;  // 10
    std::int8_t produceChance[4];  // 18
    std::uint32_t pad1C;  // 1C
};
static_assert(sizeof(TESProduceForm) == 0x20, "TESProduceForm size");
