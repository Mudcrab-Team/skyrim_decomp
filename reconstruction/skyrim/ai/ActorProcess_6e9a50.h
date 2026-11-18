// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// ActorProcess: STANDIN GUESS(low)
// ActorPackage, middleLow, middleHigh, high, currentPackage, package: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
class TESPackage; class MiddleLowProcessData; class MiddleHighProcessData; class HighProcessData; class ActorPackageData;
class ActorPackage { public: std::uint32_t packageLock; TESPackage* package; ActorPackageData* data; };
class ActorProcess { public: MiddleLowProcessData* middleLow; MiddleHighProcessData* middleHigh; HighProcessData* high; ActorPackage currentPackage; TESPackage* Function6e9a50(); TESPackage* GetPackageThatIsRunning(); TESPackage* GetSpecialPackage(); TESPackage* GetRunningOverride(); };
