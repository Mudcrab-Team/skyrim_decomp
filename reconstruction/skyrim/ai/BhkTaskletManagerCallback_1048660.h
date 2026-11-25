// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManagerCallback: EXE_RTTI
// BSTaskletManagerCallback: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkTaskletManagerCallback: STANDIN EXE_RTTI; the RTTI name is bhkTaskletManagerCallback, capitalised to fit the unit file-name pattern
#pragma once

class BSTaskletManagerCallback
{
public:
    BSTaskletManagerCallback();
    virtual ~BSTaskletManagerCallback();
};

class BhkTaskletManagerCallback : public BSTaskletManagerCallback
{
public:
    BhkTaskletManagerCallback();
    ~BhkTaskletManagerCallback() override {}
};
static_assert(sizeof(BhkTaskletManagerCallback) == 0x8, "BhkTaskletManagerCallback size from the deleting destructor");
