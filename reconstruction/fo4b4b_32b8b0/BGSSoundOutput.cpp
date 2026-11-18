// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSSoundOutput::DoGetReverbSendLevel, BGSSoundOutput::DoGetSupportsMonitor: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:141
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:147
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSSoundOutput.h, include/RE/B/BSISoundOutputModel.h and include/RE/T/TESForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x32b8b0 BGSSoundOutput::DoGetReverbSendLevel
// 0x32b8d0
#include "BGSSoundOutput.h"
float BGSSoundOutput::DoGetReverbSendLevel() const { return float(data.reverbSendPct) * 0.01f; }
bool BGSSoundOutput::DoGetSupportsMonitor(unsigned monitor) const { if (!(data.flags & 2) && (monitor == BigRumbleMonitor() || monitor == SmallRumbleMonitor())) return false; return true; }
