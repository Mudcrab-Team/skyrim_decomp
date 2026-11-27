// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectNoise, ImageSpaceEffect: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and an out-of-line destructor, the callee at 0x1553a30, which the target calls
// NoiseEntry, NoiseEntry::~NoiseEntry, entry90, entryB0, entryD0, entryF0, unk110: STANDIN GUESS(low); four 0x20-byte members at 0x90 whose destructor is the callee at 0x1554ed0, and an unread range
// ParamArray, ParamArray::SetAt, ImageSpaceEffectParam, params: STANDIN GUESS(low); the array of the NiTArray shape at 28 (vtable, data, capacity, free index, size, growth) with its set-at routine inlined, as read from the listing
// _data, _capacity, _freeIdx, _size, _growthSize: GUESS(low); the names follow NG's NiTArray members, here public
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

    ImageSpaceEffectParam*& operator[](std::uint32_t a_index) { return _data[a_index]; }

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

class NoiseEntry
{
public:
    NoiseEntry();
    ~NoiseEntry();  // callee at 0x1554ed0, not compared here
    std::uint8_t unk00[0x20];
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

class ImageSpaceEffectNoise : public ImageSpaceEffect
{
public:
    ImageSpaceEffectNoise();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x1586580
    ~ImageSpaceEffectNoise() override;

    NoiseEntry entry90;  // 90
    NoiseEntry entryB0;  // B0
    NoiseEntry entryD0;  // D0
    NoiseEntry entryF0;  // F0
    std::uint8_t unk110[0x338 - 0x110];
};
static_assert(sizeof(ImageSpaceEffectNoise) == 0x338, "ImageSpaceEffectNoise size");
