// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TestBit, treated as adapted: shaped like TestBit in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// ModelData258470, BaseForm258470, BoundObject258470, ModelForm258470, Obj258470, HasModel, ValidateForm, flags, formType, modelData: GUESS(low)
#pragma once

#include <cstdint>

struct ModelData258470
{
    std::uint32_t HasModel() const;
};

struct BaseForm258470
{
    virtual ~BaseForm258470();

    std::uint64_t unk08;     // 08
    std::uint32_t flags;     // 10
    std::uint8_t unk14[6];   // 14
    std::uint8_t formType;   // 1A
};

struct BoundObject258470 : BaseForm258470
{
};

struct ModelForm258470
{
    virtual ~ModelForm258470();

    ModelData258470 modelData;  // 08
};

class Obj258470
{
public:
    static std::uint32_t ValidateForm(BaseForm258470* form);
};
