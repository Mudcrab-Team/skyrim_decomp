// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x28f0d0 TESSoulGem::InitImpl
// 0x28f1e0 TESSoulGem::~TESSoulGem
// 0x28efd0 TESSoulGem::LoadImpl
#include "TESSoulGem.h"
TESSoulGem::TESSoulGem() {}
TESSoulGem::~TESSoulGem() { TESForm::ClearData(); }
inline bool SoulPointerPresent(const TESSoulGem* pointer) { return pointer!=nullptr; }



