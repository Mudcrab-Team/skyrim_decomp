// PlayerCharacter: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerCharacter, TESFaction, GetCrimeGoldValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ScaledCrime, globalDivisor, globalLimit, UnknownSlot: STANDIN GUESS(medium); wrapper and global identities inferred.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75ac10 ScaledCrime
#include "PlayerCharacter_75ac10.h"
namespace P2073 {
std::int32_t PlayerCharacter::ScaledCrime(const TESFaction* faction) {
    std::uint32_t divisor = globalDivisor;
    std::int32_t value = static_cast<std::int32_t>(GetCrimeGoldValue(faction) / divisor);
    std::int32_t limit = globalLimit;
    if (value > limit) return limit;
    return value < 1 ? 1 : value;
}
}
