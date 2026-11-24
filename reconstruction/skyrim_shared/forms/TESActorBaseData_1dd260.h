// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActorBaseData, TESForm, TESNPC, FormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::formType, ACTOR_BASE_DATA::templateUseFlags, TESActorBaseData::baseTemplateForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); flattened into the TESNPC stand-in at their TESNPC offsets, other bases kept as padding
// TESActorBaseData::Function1dd260, WalkTemplates, TemplateFlags, TemplateFlags::value, pad00, gap1B, gap4C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

enum class FormType : std::uint8_t
{
    NPC = 0x2B
};

class TESForm
{
public:
    std::uint8_t pad00[0x1A];
    FormType formType;  // 1A
};

// Typed 16-bit flag set standing in for NG's stl::enumeration<TEMPLATE_USE_FLAG, std::uint16_t>.
struct TemplateFlags
{
    TemplateFlags& operator&=(std::uint16_t a_mask)
    {
        value &= a_mask;
        return *this;
    }

    std::uint16_t value;
};

class TESNPC : public TESForm
{
public:
    std::uint8_t gap1B[0x4A - 0x1B];
    TemplateFlags templateUseFlags;  // 4A
    std::uint8_t gap4C[0x60 - 0x4C];
    TESForm* baseTemplateForm;  // 60
};
static_assert(offsetof(TESNPC, baseTemplateForm) == 0x60, "TESNPC::baseTemplateForm offset");

class TESActorBaseData
{
public:
    // Walks the template chain of a_form, intersecting the template-use flags, and
    // returns the first form in the chain that is not an NPC.
    static TESForm* Function1dd260(TESForm* a_form, TemplateFlags* a_flags);  // compared: 0x1dd260
};
