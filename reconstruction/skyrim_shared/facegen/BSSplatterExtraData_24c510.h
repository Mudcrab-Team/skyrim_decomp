// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/ScreenSplatter.cpp:11
// BSSplatterExtraData, BSSplatterExtraData::KillSDM: SIBLING(fo4-private@1b765c70, author-permission)
// BSSplatterExtraData::sTag: GUESS(medium); name from the sibling body
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSFixedString
{
public:
    BSFixedString(const char* a_string);
    BSFixedString& operator=(const BSFixedString& a_rhs);
    ~BSFixedString();

    const char* data;  // 00
};

class BSSplatterExtraData
{
public:
    static void KillSDM();

    static BSFixedString sTag;
};
