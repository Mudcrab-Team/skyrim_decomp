// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// BGSSaveFormBuffer: EXE_RTTI
// BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x639890 BGSSaveFormBuffer::Function639890
#include "BGSSaveFormBuffer.h"
std::uint32_t BGSSaveFormBuffer::Function639890() { return 2 * CountPosition(ConvertPosition(bufferPosition)) + 9; }
