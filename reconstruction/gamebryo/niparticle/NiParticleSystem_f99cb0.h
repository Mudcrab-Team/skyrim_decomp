// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticleSystem, NiParticles, NiTListItem, modifierList, head, tail, allocator, size, unk180, unk184, unk188, lastUpdate, resetSystem, dynamicBounds, isWorldspace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

// NiParticles: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only its constructor, destructor and size
class NiParticles
{
public:
    NiParticles();
    virtual ~NiParticles();

    std::uint8_t pad008[0x160];  // 008
};
static_assert(sizeof(NiParticles) == 0x168, "NiParticles size");

template <class T>
class NiTListItem;

// NiTPointerList: STANDIN GUESS(low); NiTListBase members flattened
template <class T>
class NiTPointerList
{
public:
    struct AntiBloatAllocator
    {
        std::uint32_t size;  // 00
    };

    // the image clears the count before the two list pointers
    NiTPointerList() { allocator.size = 0; head = nullptr; tail = nullptr; }

    NiTListItem<T>*    head;       // 00
    NiTListItem<T>*    tail;       // 08
    AntiBloatAllocator allocator;  // 10
};

class NiPSysModifier;

class NiParticleSystem : public NiParticles
{
public:
    NiParticleSystem();  // compared: 0xf99cb0
    ~NiParticleSystem() override;

    NiTPointerList<NiPSysModifier*> modifierList;   // 168
    float                           unk180;         // 180
    float                           unk184;         // 184
    float                           unk188;         // 188
    float                           lastUpdate;     // 18C
    bool                            resetSystem;    // 190
    bool                            dynamicBounds;  // 191
    bool                            isWorldspace;   // 192
};
static_assert(offsetof(NiParticleSystem, isWorldspace) == 0x192, "isWorldspace offset");
