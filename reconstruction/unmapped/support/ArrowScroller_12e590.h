// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// ArrowScroller, UI_element: EXE_RTTI
// UI_element: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class UI_element
{
public:
    UI_element();
    virtual ~UI_element();
};

class ArrowScroller : public UI_element
{
public:
    ArrowScroller();
    ~ArrowScroller() override {}

    char unk08[0x88];
};
static_assert(sizeof(ArrowScroller) == 0x90, "ArrowScroller size from the deleting destructor");
