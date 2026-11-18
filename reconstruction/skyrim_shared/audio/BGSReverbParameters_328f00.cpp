// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSReverbParameters::DoGetReverbDelay: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSReverbParameters.cpp:262
// BGSReverbParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSReverbParameters.h, include/RE/B/BSIReverbType.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x328f00 BGSReverbParameters::DoGetReverbDelay
#include "BGSReverbParameters_328f00.h"
float BGSReverbParameters::DoGetReverbDelay() const { return float(data.reverbDelay) * 0.001f; }
