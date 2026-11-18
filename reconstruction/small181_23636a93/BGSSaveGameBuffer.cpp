// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// WriteValue, SaveBlock: GUESS(low)
// 0x8f3250 BGSSaveGameBuffer::WriteValue
#include "BGSSaveGameBuffer.h"
void BGSSaveGameBuffer::WriteValue(const void* data) { SaveBlock(data, 4, 4, 0); }
