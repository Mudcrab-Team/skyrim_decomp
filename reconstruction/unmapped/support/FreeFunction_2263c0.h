// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiNode2263c0, NiAVObject2263c0, AsNode, AsGeometry, FindGeomAtIndex2263c0, name, children, childCount, gPrefixA2263c0, gPrefixB2263c0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* lhs, const char* rhs, std::size_t count);
extern const char gPrefixA2263c0[6];
extern const char gPrefixB2263c0[8];

class NiNode2263c0;

class NiAVObject2263c0
{
public:
    virtual ~NiAVObject2263c0();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode2263c0* AsNode();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void* AsGeometry();

    std::uint64_t unk08;        // 008
    const char* name;           // 010
    std::uint8_t unk18[0x100];  // 018
};

class NiNode2263c0 : public NiAVObject2263c0
{
public:
    NiAVObject2263c0** children;  // 118
    std::uint16_t maxSize;        // 120
    std::uint16_t childCount;     // 122
};

NiAVObject2263c0* FindGeomAtIndex2263c0(NiAVObject2263c0* obj, std::uint32_t& remaining, bool excludePrefixA, bool requirePrefixB);
