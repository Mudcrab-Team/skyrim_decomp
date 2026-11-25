// Source exposure: mixed (binary-analysis, community headers).
// Code origin: brown-room reconstruction from disassembly Stamped as a twin of matched 0xfde7a0 (gamebryo/nimain/NiNode): source copied, names replaced by placeholders.
// Code origin: original reconstruction from the pinned image listing; declarations from CommonLibSSE-NG (MIT). No community body copied.
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PerformOpFunc, NiTObjectArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionfde7d0, Ownerfde7d0: GUESS(low) STANDIN
// QueryFlag, Functionee2310, children, NiAVObject: GUESS(low) STANDIN
#pragma once
#include "NiNode.h"
#include <cstdint>

class Ownerfde7d0 : public NiAVObject
{
public:
	bool Functionfde7d0();
	void QueryFlag(bool* value);
	void Functionee2310(PerformOpFunc& a_func);

	NiTObjectArray<NiAVObject*> children;  // 110
};
static_assert(sizeof(Ownerfde7d0) == 0x128, "Ownerfde7d0 size");
