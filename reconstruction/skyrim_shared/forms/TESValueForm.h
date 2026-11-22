// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x1f36a0 compared function
// 0x1f3480 compared function
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESValueForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// TESValueForm::ClearDataComponent, TESValueForm::InitializeDataComponent, TESValueForm::~TESValueForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: GUESS(low)
// unk08, unknown0C: GUESS(low); unk08 is the dword the initialiser stores zero into
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

// BGSLoadGameBuffer: GUESS(low) STANDIN; the buffer the compared body reads and calls.
class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
    std::uint8_t pad00[0x40];  // 00
    std::uint32_t flags40;  // 40
};

// TestBit: GUESS(low); a flag-word bit test by index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class TESValueForm : public BaseFormComponent
{
public:
    // TESValueForm::Function1f3480: GUESS(low); placement-new factory, compared at RVA 0x1f3480
    TESValueForm* Function1f3480();
    // TESValueForm::Function1f36a0: GUESS(low); compared at RVA 0x1f36a0
    void Function1f36a0(BGSLoadGameBuffer* a_buf);
    TESValueForm() : unk08(0) {}
    virtual void ClearDataComponent();  // compared: 0x1f34d0
    virtual void InitializeDataComponent();  // compared: 0x1f34c0
    virtual ~TESValueForm();  // compared: 0x1f36d0 (scalar deleting destructor)

    std::uint32_t unk08;  // 08
    std::uint8_t unknown0C[0x4];  // 0C
};
static_assert(sizeof(TESValueForm) == 0x10, "TESValueForm size");
