// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// UI_topBar, UI_bar, UI_element: EXE_RTTI
// UI_element: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class UI_element
{
public:
    UI_element();
    virtual ~UI_element();
};

class UI_bar : public UI_element
{
public:
    UI_bar();
    ~UI_bar() override {}
};

class UI_topBar : public UI_bar
{
public:
    UI_topBar();

    char unk08[0x70];
};
static_assert(sizeof(UI_topBar) == 0x78, "UI_topBar size from the deleting destructor");
