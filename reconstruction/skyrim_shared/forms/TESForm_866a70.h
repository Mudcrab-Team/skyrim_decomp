// TESForm: STANDIN GUESS(low); partial target view; original identities and ownership remain hypotheses.
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// CombinedMeasure, Measure: GUESS(medium); target callee accepts a form pointer and returns float; purpose unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2073 {
// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); represented form prefix only, no complete layout or allocation size.
class TESForm : public P206Target::FormPrefix {};
float Measure(TESForm* form);
float CombinedMeasure(TESForm* first, TESForm* second);
}
