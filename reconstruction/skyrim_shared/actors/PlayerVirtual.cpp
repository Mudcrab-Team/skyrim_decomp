// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerVirtual: STANDIN GUESS(low); partial receiver view, not a complete class.
// Get3D2, GetBiped2, Is3rdPersonVisible, SetDelete, SetAltered, GetDecalGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BipedPointer, DecalGroup, ExtraListVirtual, Apply3D, Reset, Finish, Clear, Function2f54f0, Function2f3980, Function2e4040, GetBase3D, GetBaseBiped, Slot: STANDIN GUESS(low); inferred support declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x747af0 P2062::PlayerVirtual::Get3D2
// 0x748c50 P2062::PlayerVirtual::GetBiped2

#include "PlayerVirtual.h"
namespace P2062 {
NiAVObject* PlayerVirtual::Get3D2() const { if (!Is3rdPersonVisible() && firstPerson3D) return firstPerson3D; return GetBase3D(); }
const BipedPointer& PlayerVirtual::GetBiped2() const { if (!Is3rdPersonVisible() && largeBiped.object) return largeBiped; return GetBaseBiped(); }
}
