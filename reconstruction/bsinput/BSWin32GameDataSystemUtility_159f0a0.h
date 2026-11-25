// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// BSWin32GameDataSystemUtility, BSGameDataSystemUtility: EXE_RTTI
// BSGameDataSystemUtility: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class BSGameDataSystemUtility
{
public:
    BSGameDataSystemUtility();
    virtual ~BSGameDataSystemUtility();
};

class BSWin32GameDataSystemUtility : public BSGameDataSystemUtility
{
public:
    BSWin32GameDataSystemUtility();
    ~BSWin32GameDataSystemUtility() override {}

    char unk08[0x6D0];
};
static_assert(sizeof(BSWin32GameDataSystemUtility) == 0x6D8, "BSWin32GameDataSystemUtility size from the deleting destructor");
