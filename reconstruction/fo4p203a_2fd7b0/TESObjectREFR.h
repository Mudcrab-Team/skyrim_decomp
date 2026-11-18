// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// TESObjectREFR::ShouldSaveAnimationOnUnloading: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_Animation.cpp:133
// TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESObjectREFR.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class TESObjectREFR { public: bool ShouldSaveAnimationOnUnloading() const; };
void GetAnimationSaveDetails(const TESObjectREFR&, bool&, bool&, bool&);
