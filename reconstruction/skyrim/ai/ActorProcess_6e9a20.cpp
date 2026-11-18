// ActorProcess, Function6e9a20, Check, GetData: GUESS(low)
// middleLow, middleHigh, high, currentPackage, packageLock, package, data, ActorPackage, ActorPackageData, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and partial public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6e9a20 ActorProcess::Function6e9a20

#include "ActorProcess_6e9a20.h"
ActorPackageData* ActorProcess::Function6e9a20() { return Check() ? GetData() : currentPackage.data; }
