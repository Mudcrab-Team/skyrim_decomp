// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x18c280 (skyrim_shared/extradata/ExtraInteraction_18c280): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ::GetType, ::IsNotEqual: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order 00 to 02
// RefrInteractionPtr: GUESS(low); the pointer wrapper stands in for NG's BSTSmartPointer<RefrInteraction>
// ::IsNotEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared so the class has the vtable the constructor stores
// Owner180430: GUESS(low) STANDIN
// BSExtraData: GUESS(low) STANDIN
#pragma once
#include "ExtraInteraction_18c280.h"

class Owner180430 : public BSExtraData
{
public:
    explicit Owner180430(const RefrInteractionPtr& a_interaction);

    ~Owner180430() override;
    std::uint32_t GetType() const override;
    bool IsNotEqual(const BSExtraData* a_rhs) const override;

    RefrInteractionPtr interaction;  // 10
};
static_assert(sizeof(Owner180430) == 0x18, "Owner180430 size");
