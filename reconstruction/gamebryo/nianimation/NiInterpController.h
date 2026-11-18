// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiInterpController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiInterpController::ResetTimeExtrema, NiInterpController::~NiInterpController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "NiTimeController.h"

class NiInterpController : public NiTimeController
{
public:
    NiInterpController();
    virtual ~NiInterpController();  // compared: 0xf5fa30 (scalar deleting destructor); declared only, rule 18
};
static_assert(sizeof(NiInterpController) == 0x48, "NiInterpController size");
