// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiNode223ed0, NiAVObject223ed0, AsNode, CountMatchingNodes223ed0, name, children, childCount, gPrefix223ed0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* lhs, const char* rhs, std::size_t count);
extern const char gPrefix223ed0[6];

class NiNode223ed0;

class NiAVObject223ed0
{
public:
    virtual ~NiAVObject223ed0();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode223ed0* AsNode();

    std::uint64_t unk08;        // 008
    const char* name;           // 010
    std::uint8_t unk18[0x100];  // 018
};

class NiNode223ed0 : public NiAVObject223ed0
{
public:
    NiAVObject223ed0** children;  // 118
    std::uint16_t maxSize;        // 120
    std::uint16_t childCount;     // 122
};

std::uint32_t CountMatchingNodes223ed0(NiAVObject223ed0* obj, bool filterPrefix);
