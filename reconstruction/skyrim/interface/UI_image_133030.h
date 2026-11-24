// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// UI_image, UI_element: EXE_RTTI
// UI_element: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class UI_element
{
public:
    UI_element();
    virtual ~UI_element();
};

class UI_image : public UI_element
{
public:
    UI_image();
    ~UI_image() override {}

    char unk08[0xB0];
};
static_assert(sizeof(UI_image) == 0xB8, "UI_image size from the deleting destructor");
