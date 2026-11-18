// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x391020 BGSHeadPart::GetFormEditorID
// 0x391210 BGSHeadPart::SetFormEditorID
#include "BGSHeadPart.h"

const char* BGSHeadPart::GetFormEditorID() const
{
    return formEditorID.c_str();
}

bool BGSHeadPart::SetFormEditorID(const char* a_str)
{
    formEditorID = a_str;
    return true;
}
