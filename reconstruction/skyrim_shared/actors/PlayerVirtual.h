// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerVirtual: STANDIN GUESS(low); partial receiver view, not a complete class.
// Get3D2, GetBiped2, Is3rdPersonVisible, SetDelete, SetAltered, GetDecalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BipedPointer, DecalGroup, ExtraListVirtual, Apply3D, Reset, Finish, Clear, Function2f54f0, Function2f3980, Function2e4040, GetBase3D, GetBaseBiped, Slot: STANDIN GUESS(low); inferred support declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include "skyrim_shared/refs/VirtualREFR.h"
namespace P2062 {
class PlayerVirtual : public VirtualREFR {
  std::uint64_t unknownA0[0x10b];
  BipedPointer largeBiped;
  NiAVObject* firstPerson3D;
public:
  NiAVObject* Get3D2() const override;
  const BipedPointer& GetBiped2() const override;
  NiAVObject* GetBase3D() const;
  const BipedPointer& GetBaseBiped() const;
};
}
