// NiInterpController, NiTimeController: GUESS(low)
// _refCount, _pad0C, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and partial public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf5fa00 NiInterpController::Functionf5fa00

#include "NiInterpController.h"
NiInterpController::NiInterpController() { flags &= static_cast<std::uint16_t>(~0x20u); }
