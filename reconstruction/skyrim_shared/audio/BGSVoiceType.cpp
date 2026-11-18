// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x3aee30 BGSVoiceType::SetFormEditorID
#include "BGSVoiceType.h"

// TODO body: RVA 0x3aee30, 23 bytes, BGSVoiceType::SetFormEditorID.
bool BGSVoiceType::SetFormEditorID(const char* a_str)
{
    FormEditorIDSet(unk28, a_str, false);
    return true;
}
