// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BaseObject1eb490, PathOwner1eb490, Unit1eb490, g_extension1eb490, BuildObjectPath1eb490, Slot1, Slot2, Slot3, GetPath: GUESS(low)
#pragma once

#include <cstddef>

extern "C" __declspec(dllimport) int __cdecl strcpy_s(char* a_dest, std::size_t a_destSize, const char* a_src);
extern "C" char* __cdecl strrchr(const char* a_str, int a_ch);

extern const char g_extension1eb490[];

class BaseObject1eb490
{
public:
    virtual ~BaseObject1eb490();
};

class PathOwner1eb490 : public BaseObject1eb490
{
public:
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual const char* GetPath() const;
};

struct Unit1eb490
{
    static void BuildObjectPath1eb490(char* a_buffer, BaseObject1eb490* a_object);  // compared: 0x1eb490
};
