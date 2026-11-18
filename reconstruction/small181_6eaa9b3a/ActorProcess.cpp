// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// ActorProcess: STANDIN GUESS(low)
// ActorPackage, middleLow, middleHigh, high, currentPackage, package: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6e9a50 ActorProcess::Function6e9a50
// 0x6e9a80 ActorProcess::GetPackageThatIsRunning
#include "ActorProcess.h"
TESPackage* ActorProcess::Function6e9a50() { auto package = GetSpecialPackage(); return package ? package : currentPackage.package; }
TESPackage* ActorProcess::GetPackageThatIsRunning() { auto package = GetRunningOverride(); return package ? package : currentPackage.package; }
