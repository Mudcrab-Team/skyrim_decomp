// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkTaskletManagerCallback, BSTaskletManagerCallback: EXE_RTTI
// BSTaskletManagerCallback: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkOnStartupCallback: STANDIN EXE_RTTI; the RTTI name is bhkOnStartupCallback, capitalised to fit the unit file-name pattern
#pragma once

class BSTaskletManagerCallback
{
public:
    BSTaskletManagerCallback();
    virtual ~BSTaskletManagerCallback();
};

class bhkTaskletManagerCallback : public BSTaskletManagerCallback
{
public:
    bhkTaskletManagerCallback();
    ~bhkTaskletManagerCallback() override {}
};

class BhkOnStartupCallback : public bhkTaskletManagerCallback
{
public:
    BhkOnStartupCallback();
};
static_assert(sizeof(BhkOnStartupCallback) == 0x8, "BhkOnStartupCallback size from the deleting destructor");
