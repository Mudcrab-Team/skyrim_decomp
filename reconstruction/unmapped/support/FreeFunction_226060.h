// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiNode226060, NiAVObject226060, AsNode, FindNodeAtIndex226060, name, children, childCount, gPrefix226060: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __cdecl _strnicmp(const char* lhs, const char* rhs, std::size_t count);
extern const char gPrefix226060[6];

class NiNode226060;

class NiAVObject226060
{
public:
    virtual ~NiAVObject226060();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode226060* AsNode();

    std::uint64_t unk08;        // 008
    const char* name;           // 010
    std::uint8_t unk18[0x100];  // 018
};

class NiNode226060 : public NiAVObject226060
{
public:
    NiAVObject226060** children;  // 118
    std::uint16_t maxSize;        // 120
    std::uint16_t childCount;     // 122
};

NiAVObject226060* FindNodeAtIndex226060(NiAVObject226060* obj, std::uint32_t& remaining, bool filterPrefix);
