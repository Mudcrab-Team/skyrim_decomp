// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceEffectWaterDisplacement, ImageSpaceEffect: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and an out-of-line destructor, the callee at 0x1553a30, which the target calls
// DisplacementTexture, texture, unk98: STANDIN GUESS(low); a pointer member at 0x90 that the destructor releases; DeleteThis is virtual slot 01
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// ParamArray, ParamArray::SetAt, ImageSpaceEffectParam, params: STANDIN GUESS(low); the array of the NiTArray shape at 28 (vtable, data, capacity, free index, size, growth) with its set-at routine inlined, as read from the listing
// NiTArray::_data, NiTArray::_capacity, NiTArray::_freeIdx, NiTArray::_size, NiTArray::_growthSize: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the member names, here public on ParamArray
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();  // 01

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;

    void DecRefCount()
    {
        // hot path: the engine releases references atomically, as NiRefObject::DecRefCount does
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0) {
            DeleteThis();
        }
    }
};

template <class T>
class NiPointer
{
public:
    NiPointer() : _ptr(nullptr) {}
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }

    T* _ptr;
};

class ImageSpaceEffectParam
{
public:
    virtual ~ImageSpaceEffectParam();
};

class ParamArray
{
public:
    virtual ~ParamArray();

    void SetAt(std::uint32_t a_index, ImageSpaceEffectParam* a_element)
    {
        if (a_index >= _freeIdx) {
            _freeIdx = static_cast<std::uint16_t>(a_index + 1);
            if (a_element) {
                ++_size;
            }
        } else if (_data[a_index]) {
            if (!a_element) {
                --_size;
            }
        } else if (a_element) {
            ++_size;
        }
        _data[a_index] = a_element;
    }

    ImageSpaceEffectParam** _data;  // 08
    std::uint16_t _capacity;        // 10
    std::uint16_t _freeIdx;         // 12
    std::uint16_t _size;            // 14
    std::uint16_t _growthSize;      // 16
};

class ImageSpaceEffect
{
public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();

    std::uint8_t unk08[0x20];
    ParamArray params;  // 28
    std::uint8_t unk40[0x50];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectWaterDisplacement : public ImageSpaceEffect
{
public:
    ImageSpaceEffectWaterDisplacement();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x155c090
    ~ImageSpaceEffectWaterDisplacement() override;

    NiPointer<NiRefObject> texture;  // 90
    std::uint8_t unk98[0x18];
};
static_assert(sizeof(ImageSpaceEffectWaterDisplacement) == 0xb0, "ImageSpaceEffectWaterDisplacement size");
