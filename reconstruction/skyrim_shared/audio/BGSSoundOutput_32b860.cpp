// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSSoundOutput::DoGetAudibility: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:129
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSSoundOutput.h, include/RE/B/BSISoundOutputModel.h and include/RE/T/TESForm.h.
// names: GUESS(low); signatures and global interpretation remain provisional.
// 0x32b860 BGSSoundOutput::DoGetAudibility
#include "BGSSoundOutput_32b860.h"
bool BGSSoundOutput::DoGetAudibility(float distance) const { float maximum = attenuation ? attenuation->GetMaxDistance() : MaxSoundDistance; return maximum > distance; }
