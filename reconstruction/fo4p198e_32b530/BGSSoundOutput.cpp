// Source exposure: mixed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSSoundOutput::ClearData: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:51
// BGSSoundOutput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSSoundOutput.h, include/RE/B/BSISoundOutputModel.h and include/RE/T/TESForm.h.
// names: GUESS(low); signatures and ownership remain provisional.
// 0x32b530 BGSSoundOutput::ClearData
#include "BGSSoundOutput.h"
void operator delete(void*, std::size_t) noexcept;
void BGSSoundOutput::ClearData() { delete attenuation; SpeakerArrays* arrays = speakerOutputs; attenuation = nullptr; operator delete(arrays, sizeof(SpeakerArrays)); speakerOutputs = nullptr; }
