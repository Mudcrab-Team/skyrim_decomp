// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// QueryStatus, HasStatus: GUESS(low)
// 0xeadeb0 BSFile::HasStatus
#include "BSFile.h"
bool BSFile::HasStatus() { return QueryStatus(0) != 0; }
