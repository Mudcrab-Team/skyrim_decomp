// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectACTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InitBaseComponents: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObjectACTI : public TESForm
{
public:
    void InitItemImpl() override;

private:
    void InitBaseComponents();
};
