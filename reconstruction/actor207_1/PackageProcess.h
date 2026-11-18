// PackageProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix declarations adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
#include <cstdint>
namespace P2071 {
// PackagePrefix: STANDIN GUESS(medium); only accessed public prefix is represented.
struct PackagePrefix {
    P206Target::FormPrefix form;
    // packFlags, packType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    std::uint32_t packFlags;
    std::uint8_t packType;
};
// PackageProcess: STANDIN GUESS(low); process layout and ownership unknown.
class PackageProcess { public:
    // RunningPackage: GUESS(low); candidate association with public GetRunningPackage unconfirmed.
    PackagePrefix* RunningPackage();
};
// PackageActor: STANDIN GUESS(medium); partial receiver with target process pointer.
using PackageActor = P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, PackageProcess>;
// FindPackage, HasPackageType29, ScriptIsAlarmed: GUESS(low); names and receiver identity unconfirmed.
PackagePrefix* FindPackage(PackageActor*);
bool HasPackageType29(PackageActor*);
bool ScriptIsAlarmed(void*, unsigned, PackageActor*);
}
