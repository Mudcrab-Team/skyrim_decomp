// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// 0x27bb70 TESObjectANIO::GetFormEditorID
// 0x27b9b0 TESObjectANIO::InitItemImpl
// Adapted bodies: none
#include "TESObjectANIO.h"

// Callees of the compared member below: GUESS(low); declared without bodies; the compare binds each call by position.
void TESObjectANIOInitSub(void* a_sub, TESObjectANIO* a_owner);  // RVA 0x1ed110
void FinishInitItem(TESForm* a_owner, bool a_flag);              // RVA 0x1e60b0

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
static bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

const char* TESObjectANIO::GetFormEditorID() const
{
    return editorID ? editorID : g_defaultFormEditorIDString;
}


// TESObjectANIO::InitItemImpl, RVA 0x27b9b0, 52 bytes. Initializes the embedded component, then the form.
void TESObjectANIO::InitItemImpl()
{
    if (!TestBit(formFlags, 3)) {
        TESObjectANIOInitSub(reinterpret_cast<std::uint8_t*>(this) + 0x20, this);
        FinishInitItem(this, true);
    }
}
