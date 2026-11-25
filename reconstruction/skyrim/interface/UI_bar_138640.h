// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// UI_bar, UI_element: EXE_RTTI
// UI_element: STANDIN EXE_RTTI; only its out-of-line destructor is declared
// UI_element::~UI_element: CRASHLOGGER_PDB(59818@2026.10.24)
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

    char unk08[0x60];
};
static_assert(sizeof(UI_bar) == 0x68, "UI_bar size from the deleting destructor");
