// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: existing community layout; slot-test declaration inferred from the listing, with its name from CrashLogger.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSBipedObjectForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSBipedObjectForm::ClearDataComponent, BGSBipedObjectForm::InitializeDataComponent, BGSBipedObjectForm::~BGSBipedObjectForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: GUESS(low)
// unk08, unknown0C: GUESS(low); unk08 is the dword the initialiser stores zero into
// BGSBipedObjectForm::FillsBipedSlot: CRASHLOGGER_PDB(59818@2026.10.24)
// a_slot: GUESS(low); signed bit index observed in the slot-mask test
#pragma once
#include <cstddef>
#include <cstdint>

namespace ReconstructedBGSBipedObjectForm {


#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class BGSBipedObjectForm : public BaseFormComponent
{
public:
    bool Function1d2160(const BGSBipedObjectForm* a_other) const;

public:
    BGSBipedObjectForm();
    bool FillsBipedSlot(std::int32_t a_slot) const;
    virtual void ClearDataComponent();  // compared: 0x1d20f0
    virtual void InitializeDataComponent();  // compared: 0x1d20e0
    virtual ~BGSBipedObjectForm();  // compared: 0x1d21f0 (scalar deleting destructor)

    std::uint32_t unk08;  // 08
    std::uint8_t unknown0C[0x4];  // 0C
};
static_assert(sizeof(BGSBipedObjectForm) == 0x10, "BGSBipedObjectForm size");


}
