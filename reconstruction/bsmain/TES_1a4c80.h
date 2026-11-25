// Source exposure: mixed (pinned community declarations and private target analysis).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TES::Function1a4c80, g_tesSelectorZero, g_tesSelectorOne, g_tesSelectorTwo, g_tesSelectorDefault: GUESS(low); purpose and return type remain uncertain
#pragma once

#include <cstdint>

extern const char g_tesSelectorZero[];
extern const char g_tesSelectorOne[];
extern const char g_tesSelectorTwo[];
extern const char g_tesSelectorDefault[];

class TES
{
public:
    static const void* Function1a4c80(std::int32_t selector);
};
