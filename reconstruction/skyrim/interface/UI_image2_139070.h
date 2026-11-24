// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// UI_image2, UI_element2: EXE_RTTI
// UI_element2: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class UI_element2
{
public:
    UI_element2();
    virtual ~UI_element2();
};

class UI_image2 : public UI_element2
{
public:
    UI_image2();
    ~UI_image2() override {}

    char unk08[0xB0];
};
static_assert(sizeof(UI_image2) == 0xB8, "UI_image2 size from the deleting destructor");
