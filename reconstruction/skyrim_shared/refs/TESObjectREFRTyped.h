// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// TESObjectREFRTyped: STANDIN GUESS(low); receiver identity is provisional.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include "skyrim_shared/actors/ActorTargetPrefix.h"
namespace P2062 {
// NiPoint3, TESObjectREFR, OBJ_REFR, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraAnim: GUESS(low); return payload based on observed access.
// Function2f1010, Function2f1050, Function2f1090, Function301500, Function301540, UpdatePosition, FindType, FindState, SetFlag, Notify: GUESS(low); signatures are inferred.
// GetAnimNoteReceiver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
using NiPoint3 = P206Target::NiPoint3;
struct BSAnimNoteReceiver;
struct ExtraAnim { std::uint64_t unknown0, unknown8; BSAnimNoteReceiver* receiver; };
struct ExtraListRef : P206Target::ExtraDataListPrefix { ExtraAnim* FindType(unsigned); };
struct StateRef { std::uint64_t unknown0, unknown8; void* value; };
class TESObjectREFRTyped : public P206Target::ReferencePrefix<ExtraListRef> {
public:
  BSAnimNoteReceiver* GetAnimNoteReceiver();
  void Function2f1010(float);
  void Function2f1050(float);
  void Function2f1090(float);
  void Function301500();
  void Function301540();
  void UpdatePosition(const NiPoint3&);
  StateRef* FindState();
  void Notify();
};
void SetFlag(void*,bool);
}
