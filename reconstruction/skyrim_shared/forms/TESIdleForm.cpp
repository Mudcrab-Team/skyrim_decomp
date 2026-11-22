// Source exposure: mixed. Existing unit plus original reconstruction of GetFormEditorID from local listings.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3b8200 TESIdleForm::~TESIdleForm
// 0x3b7240 TESIdleForm::InitItemImpl
// 0x3b82d0 TESIdleForm::GetFormEditorID
#include "TESIdleForm.h"

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
TESIdleForm::TESIdleForm()
{
}

// Callees of the compared member below: GUESS(low); declared without bodies, bound by RVA in bind-hints.json.
void              TESIdleFormInitSub(void* a_sub, TESIdleForm* a_owner);                       // RVA 0x4a6940
std::uint64_t     GetCompileIndexForOwner(TESIdleForm* a_owner, std::uint32_t a_mask);          // RVA 0x1e5ae0
void              RecordFlags_AddCompileIndex(std::uint32_t* a_formID, std::uint64_t a_compileIndex);  // RVA 0x1e6d00
TESForm*          GetFormForID(std::uint32_t a_formID);                                         // RVA 0x1e5860
void              FinishInitItem(TESIdleForm* a_owner, bool a_flag);                            // RVA 0x1e60b0

// TestBit: GUESS(low); tests one bit of a word by value.
static bool TestBit(std::uint32_t a_word, std::uint32_t a_bit)
{
    const std::uint32_t shifted = a_word >> a_bit;
    return (shifted & 1u) != 0u;
}

// TESIdleForm::InitItemImpl, RVA 0x3b7240, 319 bytes. Initializes an embedded base, then resolves the two
// stored form IDs into TESIdleForm pointers; a form that does not cast gets its detailed string queried.
void TESIdleForm::InitItemImpl()
{
    auto* base = reinterpret_cast<std::uint8_t*>(this);
    if (!TestBit(formFlags, 3)) {
        TESIdleFormInitSub(base + 0x20, this);

        std::uint32_t formID = *reinterpret_cast<std::uint32_t*>(base + 0x38);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            TESIdleForm* obj = dynamic_cast<TESIdleForm*>(GetFormForID(formID));
            if (obj == nullptr) {
                char buffer[0x200];
                GetFormDetailedString(buffer, 0x200);
            }
            *reinterpret_cast<TESIdleForm**>(base + 0x38) = obj;
        }

        formID = *reinterpret_cast<std::uint32_t*>(base + 0x40);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            TESIdleForm* obj = dynamic_cast<TESIdleForm*>(GetFormForID(formID));
            if (obj == nullptr) {
                char buffer[0x200];
                GetFormDetailedString(buffer, 0x200);
            }
            *reinterpret_cast<TESIdleForm**>(base + 0x40) = obj;
        }

        FinishInitItem(this, true);
    }
}

const char* TESIdleForm::GetFormEditorID() const
{
    return formEditorID ? formEditorID : "";
}
