// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// 0x281530 TESObjectCONT::InitializeData
// 0x281a30 TESObjectCONT::InitItemImpl
#include "TESObjectCONT.h"

// Callees of the compared member below: GUESS(low); declared without bodies; the compare binds each call by position.
void     TESObjectCONTInitSub30(void* a_sub, TESObjectCONT* a_owner);   // RVA 0x1e01d0
void     TESObjectCONTInitSubA0(void* a_sub, TESObjectCONT* a_owner);   // RVA 0x1d2dc0
void     TESObjectCONTInitSub58(void* a_sub, TESObjectCONT* a_owner);   // RVA 0x1ed110
TESFile* TESObjectCONTGetFile(TESObjectCONT* a_form, int a_idx);        // RVA 0x1e5ae0
void     TESObjectCONTAddCompileIndex(std::uint32_t& a_id, TESFile* a_file);  // RVA 0x1e6d00
TESForm* LookupFormByID(std::uint32_t a_formID);                        // RVA 0x559a10
void     FinishInitItem(TESForm* a_owner, bool a_flag);                 // RVA 0x1e60b0

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

void TESObjectCONT::InitializeData()
{
    unkB9 = 0;
    unkC0 = 0;
    unkC8 = 0;
}

void TESObjectCONT::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        auto* base = reinterpret_cast<std::uint8_t*>(this);
        TESObjectCONTInitSub30(base + 0x30, this);
        TESObjectCONTInitSubA0(base + 0xA0, this);
        TESObjectCONTInitSub58(base + 0x58, this);

        std::uint32_t id = static_cast<std::uint32_t>(unkC0);
        if (id != 0) {
            TESObjectCONTAddCompileIndex(id, TESObjectCONTGetFile(this, -1));
            unkC0 = reinterpret_cast<std::uint64_t>(LookupFormByID(id));  // 0xC0 holds a form id until this step, then the form pointer
        }

        id = static_cast<std::uint32_t>(unkC8);
        if (id != 0) {
            TESObjectCONTAddCompileIndex(id, TESObjectCONTGetFile(this, -1));
            unkC8 = reinterpret_cast<std::uint64_t>(LookupFormByID(id));  // 0xC8 holds a form id until this step, then the form pointer
        }

        FinishInitItem(this, true);
    }
}
