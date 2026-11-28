// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1ead70, g_extension1ead70, BuildReplacedPath1ead70, Slot0, Slot1, Slot2, Slot3, GetPath: GUESS(low)
#pragma once

#include <cstddef>

extern "C" __declspec(dllimport) int __cdecl strcpy_s(char* a_dest, std::size_t a_destSize, const char* a_src);
extern "C" char* __cdecl strrchr(const char* a_str, int a_ch);

extern const char g_extension1ead70[];

class Unit1ead70
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual const char* GetPath() const;

    void BuildReplacedPath1ead70(char* a_buffer) const;  // compared: 0x1ead70
};
