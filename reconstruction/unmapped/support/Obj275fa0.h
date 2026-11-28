// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// SceneObj275fa0, Obj275fa0, Obj275fa0::Function275fa0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* a_lhs, const char* a_rhs);

class SceneObj275fa0;

struct ChildPtr275fa0
{
    SceneObj275fa0* ptr;  // 0x00
};

class SceneObj275fa0
{
public:
    virtual void V00();
    virtual void V08();
    virtual void V10();
    virtual SceneObj275fa0* AsNode();
    virtual void V20();
    virtual void V28();
    virtual void V30();
    virtual SceneObj275fa0* AsGeometry();

    std::uint8_t unk08[0x08];   // 0x008
    const char* name10;         // 0x010
    std::uint8_t unk18[0x100];  // 0x018
    ChildPtr275fa0* children;   // 0x118
    std::uint16_t unk120;       // 0x120
    std::uint16_t childCount;   // 0x122
};

class Obj275fa0
{
public:
    static SceneObj275fa0* Function275fa0(SceneObj275fa0* a_object, const char* a_name);
};

static_assert(offsetof(SceneObj275fa0, name10) == 0x10, "name10 offset");
static_assert(offsetof(SceneObj275fa0, children) == 0x118, "children offset");
static_assert(offsetof(SceneObj275fa0, childCount) == 0x122, "childCount offset");
