// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Layout beyond TESForm is not claimed. Adapted bodies: none declared.
// TESTopic, TESTopic::IsFormTypeChild: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kInfoFormType: GUESS(low); the form type byte 0x4c the target compares against, NG's FormType::Info
#pragma once

#include <cstdint>

#include "TESForm.h"

class TESTopic : public TESForm {
public:
    bool IsFormTypeChild(FormType a_type) override;  // 36
};
