// Source exposure: mixed (pinned image analysis and community declarations).
// Code origin: original hand-written reconstruction; declarations adapted from the labelled community header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPrimitive, ExtraPrimitive::~ExtraPrimitive, BSExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSPrimitive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the observed destructor slot
// ExtraPrimitive::primitive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraPrimitive::ExtraPrimitive: GUESS(low); stand-in constructor to emit the virtual table
// 0x17d610 ExtraPrimitive::~ExtraPrimitive
#include "ExtraPrimitive_17d610.h"

ExtraPrimitive::ExtraPrimitive() {}

ExtraPrimitive::~ExtraPrimitive()
{
    delete primitive;
}
