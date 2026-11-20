// Origin: original reconstruction; class declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// WriteValue, SaveBlock: GUESS(low)
#pragma once
#include <cstdint>
class BGSSaveGameBuffer { public:
 void WriteValue(const void* data);
 void SaveBlock(const void* data, std::uint32_t size, std::uint32_t elementSize, std::uint32_t flags);
};
