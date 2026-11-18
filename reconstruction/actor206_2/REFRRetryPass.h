// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// REFRRetryPass, ExtraAnimRetry, ExtraListRetry, FindType, Function2f1050, Function2f1090, Function2f6310, UpdatePosition, FindObject, Read: STANDIN GUESS(low); inferred receiver and callee signatures.
// GetAnimNoteReceiver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include "actors/ActorTargetPrefix.h"
namespace P2062 {
struct BSAnimNoteReceiver;
struct ExtraAnimRetry { std::uint64_t unknown0, unknown8; BSAnimNoteReceiver* receiver; };
struct ExtraListRetry : P206Target::ExtraDataListPrefix { ExtraAnimRetry* FindType(unsigned); };
void Read(void*);
class REFRRetryPass : public P206Target::ReferencePrefix<ExtraListRetry> {
public:
 BSAnimNoteReceiver* GetAnimNoteReceiver();
 void Function2f6310();
 void* FindObject();
};
}
