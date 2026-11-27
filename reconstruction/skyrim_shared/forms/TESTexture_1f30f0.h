// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Code origin: declarations retained from the labelled existing local unit; new members inferred from the local listing.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// TESTexture::GetMaxAllowedSize, TESTexture::ClearDataComponent, TESTexture::GetDefaultPath: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>

namespace ReconstructedTESTexture {


#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESTexture : public BaseFormComponent
{
public:
    static bool Function1f30f0(std::uint32_t a_record);

public:
    virtual std::uint32_t GetMaxAllowedSize();  // compared: 0x146760
    virtual void ClearDataComponent();  // compared: 0x1f2b20
    virtual const char* GetDefaultPath() const;  // compared: 0x1f3320

    // keeping every offset and the size check true.
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");


}
