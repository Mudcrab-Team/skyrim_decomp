// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x32a7c0 BGSSoundDescriptorForm::SetFormEditorID
#include "BGSSoundDescriptorForm.h"

// SetEditorIDFromString: GUESS(low)
void SetEditorIDFromString(const char* a_str, BGSSoundDescriptorForm* a_form);

// RVA 0x32a7c0, 25 bytes, BGSSoundDescriptorForm::SetFormEditorID.
bool BGSSoundDescriptorForm::SetFormEditorID(const char* a_str)
{
    SetEditorIDFromString(a_str, this);
    return true;
}
