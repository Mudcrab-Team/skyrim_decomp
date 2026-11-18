// ActorProcess, Function6e9a20, Check, GetData: GUESS(low)
// middleLow, middleHigh, high, currentPackage, packageLock, package, data, ActorPackage, ActorPackageData, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and partial public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// ActorProcess, Function6e9a20, Check, GetData: GUESS(low)
// middleLow, middleHigh, high, currentPackage, packageLock, package, data, ActorPackage, ActorPackageData, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class MiddleLowProcessData; class MiddleHighProcessData; class HighProcessData; class TESPackage; class ActorPackageData;
struct ActorPackage { std::uint32_t packageLock; TESPackage* package; ActorPackageData* data; };
class ActorProcess {
public:
    void* Check();
    ActorPackageData* GetData();
    ActorPackageData* Function6e9a20();
    MiddleLowProcessData* middleLow;
    MiddleHighProcessData* middleHigh;
    HighProcessData* high;
    ActorPackage currentPackage;
};
