// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// UI_Text3, UI_Text: EXE_RTTI
// UI_Text: STANDIN EXE_RTTI; only its out-of-line destructor is declared
// UI_Text::~UI_Text: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class UI_Text
{
public:
    UI_Text();
    virtual ~UI_Text();
};

class UI_Text3 : public UI_Text
{
public:
    UI_Text3();
    ~UI_Text3() override {}

    char unk08[0xF0];
};
static_assert(sizeof(UI_Text3) == 0xF8, "UI_Text3 size from the deleting destructor");
