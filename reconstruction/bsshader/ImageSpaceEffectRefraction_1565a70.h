// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectRefraction, ImageSpaceEffect, ImageSpaceEffectParam: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and an out-of-line destructor, the callee at 0x1553a30
// ParamArray, ParamArray::SetAt, _data, _capacity, _freeIdx, _size, _growthSize, params: STANDIN GUESS(low); the array at 28 with its set-at routine inlined, as read from the listing
// OwnedBuffer, Function15550a0, Function15550d0, buffer: GUESS(low); the member at 90 and the callees at 0x15550a0, 0x15550d0 and 0x1554ed0
#pragma once

#include <cstdint>
#include <cstddef>

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
    virtual ~ImageSpaceEffect();  // callee at 0x1553a30, not compared here

    std::uint8_t unk08[0x20];
    ParamArray params;  // 28
    std::uint8_t unk40[0x50];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class OwnedBuffer
{
public:
    ~OwnedBuffer();  // callee at 0x1554ed0, not compared here

    void* Function15550a0();  // callee at 0x15550a0, not compared here
    void Function15550d0();   // callee at 0x15550d0, not compared here

    std::uint8_t unk00[0x20];
};

class ImageSpaceEffectRefraction : public ImageSpaceEffect
{
public:
    ImageSpaceEffectRefraction();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x1565a70
    ~ImageSpaceEffectRefraction() override;

    OwnedBuffer buffer;  // 90
};
static_assert(sizeof(ImageSpaceEffectRefraction) == 0xb0, "ImageSpaceEffectRefraction size");
