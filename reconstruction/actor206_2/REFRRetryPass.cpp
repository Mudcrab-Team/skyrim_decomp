// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// REFRRetryPass, ExtraAnimRetry, ExtraListRetry, FindType, Function2f1050, Function2f1090, Function2f6310, UpdatePosition, FindObject, Read: STANDIN GUESS(low); inferred receiver and callee signatures.
// GetAnimNoteReceiver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2f56b0 P2062::REFRRetryPass::GetAnimNoteReceiver
// 0x2f6310 P2062::REFRRetryPass::Function2f6310

#include "REFRRetryPass.h"
namespace P2062 {
BSAnimNoteReceiver* REFRRetryPass::GetAnimNoteReceiver() { auto e=extraList.FindType(0x69); if (!e) return reinterpret_cast<BSAnimNoteReceiver*>(e); return e->receiver; }
void REFRRetryPass::Function2f6310() { auto form=reinterpret_cast<P206Target::FormPrefix*>(data.objectReference); if (form->formType == 0x1f) { auto p=FindObject(); if (p) Read(static_cast<char*>(p)+8); } }
}
